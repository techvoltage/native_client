// Copyright (c) 2009 The Native Client Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/basictypes.h"
#if !NACL_LINUX
// This bit of ugliness is because base/basictypes.h defines CHECK
// on Linux but not elsewhere.
#include "native_client/src/shared/platform/nacl_check.h"
#endif
#include "native_client/src/trusted/desc/nacl_desc_base.h"
#include "native_client/src/trusted/desc/nrd_xfer_effector.h"

namespace base {
class SharedMemory;
class SyncSocket;
}  // namespace base

class TransportDIB;

namespace nacl {
// Forward declaration.
class DescWrapper;

// Descriptor creation and manipulation sometimes requires additional state
// (for instance, Effectors).  Therefore, we create an object that encapsulates
// that state.
class DescWrapperCommon {
 public:
  DescWrapperCommon() : is_initialized_(false), ref_count_(0) {
    sockets_[0] = NULL;
    sockets_[1] = NULL;
  }
  ~DescWrapperCommon();

  // Set up the state.  Returns true on success.
  bool Init();

  // Get a pointer to the effector.
  struct NaClDescEffector* effp() {
    return reinterpret_cast<struct NaClDescEffector*>(&eff_);
  }

  // Inform clients that the object was successfully initialized.
  bool is_initialized() const { return is_initialized_; }

  // Manipulate reference count
  void AddRef() {
    ++ref_count_;
    CHECK(ref_count_ > 0);
  }
  void RemoveRef() {
    CHECK(ref_count_ > 0);
    --ref_count_;
  }

 private:
  // Shut down a partially or fully created factory.
  void Cleanup();

  // Boolean to indicate the object was successfully initialized.
  bool is_initialized_;
  // Effector for transferring descriptors.
  struct NaClNrdXferEffector eff_;
  // The reference count.
  uint32_t ref_count_;
  // Bound socket, socket address pair (used for effectors).
  struct NaClDesc* sockets_[2];

  DISALLOW_COPY_AND_ASSIGN(DescWrapperCommon);
};

// We also create a utility class that allows creation of wrappers for the
// NaClDescs.
class DescWrapperFactory {
 public:
  DescWrapperFactory();
  ~DescWrapperFactory();

  // Create a bound socket, socket address pair.
  int MakeBoundSock(DescWrapper* pair[2]);
  // Create a shared memory object.
  DescWrapper* MakeShm(size_t size);
  // Create a DescWrapper from a base::SharedMemory
  DescWrapper* ImportSharedMemory(base::SharedMemory* shm);
  // Create a DescWrapper from a TransportDIB
  DescWrapper* ImportTransportDIB(TransportDIB* dib);
  // Create a DescWrapper from a base::SyncSocket
  DescWrapper* ImportSyncSocket(base::SyncSocket* sock);

  // We will doubtless want more specific factory methods.  For now,
  // we provide a wide-open method.
  DescWrapper* MakeGeneric(struct NaClDesc* desc);

 private:
  // Utility routine for importing Linux/Mac (posix) and Windows shared memory.
  DescWrapper* ImportShmHandle(NaClHandle handle, size_t size);
  // Utility routine for importing SysV shared memory.
  DescWrapper* ImportSysvShm(int key, size_t size);
  // The common data from this instance of the wrapper.
  DescWrapperCommon* common_data_;

  DISALLOW_COPY_AND_ASSIGN(DescWrapperFactory);
};

// A wrapper around NaClDesc to provide slightly higher level abstractions for
// common operations.
class DescWrapper {
 public:
  struct MsgIoVec {
    void*  base;
    size_t length;
  };

  struct MsgHeader {
    struct MsgIoVec* iov;
    nacl_abi_size_t  iov_length;
    DescWrapper**    ndescv;  // Pointer to array of pointers.
    nacl_abi_size_t  ndescv_length;
    int32_t          flags;
  };

  DescWrapper(DescWrapperCommon* common_data, struct NaClDesc* desc);
  ~DescWrapper();

  // Extract a NaClDesc from the wrapper.
  struct NaClDesc* desc() const { return desc_; }

  // We do not replicate the underlying NaClDesc object hierarchy, so there
  // are obviously many more methods than a particular derived class
  // implements.

  // Map a shared memory descriptor in at the given address
  // Uses the NaCl ABI prots and flags.
  // Returns the address at which the descriptor was mapped on success.
  // [-64K, -1] as NaCl ABI errno on failure.
  void* Map(void* start_addr,
            size_t len,
            int prot,
            int flags,
            nacl_off64_t offset);

  // Unmaps a region of shared memory.
  // Returns zero on success, negative NaCl ABI errno on failure.
  int Unmap(void* start_addr, size_t len);

  // Read len bytes into buf.
  // Returns bytes read on success, negative NaCl ABI errno on failure.
  ssize_t Read(void* buf, size_t len);

  // Write len bytes from buf.
  // Returns bytes written on success, negative NaCl ABI errno on failure.
  ssize_t Write(const void* buf, size_t len);

  // Move the file pointer.
  // Returns updated position on success, negative NaCl ABI errno on failure.
  nacl_off64_t Seek(nacl_off64_t offset, int whence);

  // The generic I/O control function.
  // Returns zero on success, negative NaCl ABI errno on failure.
  int Ioctl(int request, void* arg);

  // Get descriptor information.
  // Returns zero on success, negative NaCl ABI errno on failure.
  int Fstat(struct nacl_abi_stat* statbuf);

  // Close the descriptor.
  // Returns zero on success, negative NaCl ABI errno on failure.
  int Close();

  // Read count directory entries into dirp.
  // Returns count on success, negative NaCl ABI errno on failure.
  ssize_t Getdents(void* dirp, size_t count);

  // Lock a mutex.
  // Returns zero on success, negative NaCl ABI errno on failure.
  int Lock();

  // TryLock on a mutex.
  // Returns zero on success, negative NaCl ABI errno on failure.
  int TryLock();

  // Unlock a mutex.
  // Returns zero on success, negative NaCl ABI errno on failure.
  int Unlock();

  // Wait on a condition variable guarded by the specified mutex.
  // Returns zero on success, negative NaCl ABI errno on failure.
  int Wait(DescWrapper* mutex);

  // Timed wait on a condition variable guarded by the specified mutex.
  // Returns zero on success, negative NaCl ABI errno on failure.
  int TimedWaitAbs(DescWrapper* mutex, struct nacl_abi_timespec* ts);

  // Signal a condition variable.
  // Returns zero on success, negative NaCl ABI errno on failure.
  int Signal();

  // Broadcast to a condition variable.
  // Returns zero on success, negative NaCl ABI errno on failure.
  int Broadcast();

  // Send a message.
  // Returns bytes sent on success, negative NaCl ABI errno on failure.
  int SendMsg(const MsgHeader* dgram, int flags);

  // Receive a message.
  // Returns bytes received on success, negative NaCl ABI errno on failure.
  int RecvMsg(MsgHeader* dgram, int flags);

  // Connect to a socket address.
  // Returns a valid DescWrapper on success, NULL on failure.
  DescWrapper* Connect();

  // Accept connection on a bound socket.
  // Returns a valid DescWrapper on success, NULL on failure.
  DescWrapper* Accept();

  // Post on a semaphore.
  // Returns zero on success, negative NaCl ABI errno on failure.
  int Post();

  // Wait on a semaphore.
  // Returns zero on success, negative NaCl ABI errno on failure.
  int SemWait();

  // Get a semaphore's value.
  // Returns zero on success, negative NaCl ABI errno on failure.
  int GetValue();

 private:
  DescWrapperCommon* common_data_;
  struct NaClDesc* desc_;
  DISALLOW_COPY_AND_ASSIGN(DescWrapper);
};
}  // namespace nacl
