// Copyright (c) 2020, NVIDIA CORPORATION. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of NVIDIA CORPORATION nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
// OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#pragma once

#include <list>
#include "backend_manager.h"
#include "constants.h"
#include "model_config.h"
#include "status.h"

namespace triton { namespace core {

//
// A single manager across all InferenceServer objects that keeps the
// persistent backends loaded as long as there is at least one
// InferenceServer object.
//
class PersistentBackendManager {
 public:
  static Status Create(
      const BackendCmdlineConfigMap& config_map,
      std::shared_ptr<PersistentBackendManager>* manager);

 private:
  DISALLOW_COPY_AND_ASSIGN(PersistentBackendManager);
  PersistentBackendManager() = default;
  Status InitPersistentBackends(const BackendCmdlineConfigMap& config_map);
  Status InitPersistentBackend(
      const std::string& backend_name,
      const BackendCmdlineConfigMap& config_map);

  std::list<std::shared_ptr<TritonBackend>> persist_backends_;
};

}}  // namespace triton::core
