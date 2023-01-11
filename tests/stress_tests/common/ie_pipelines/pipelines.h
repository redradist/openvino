// Copyright (C) 2018-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <string>
#include <functional>
#include <inference_engine.hpp>
#include "../infer_api/infer_api.h"

std::function<void()> load_unload_plugin(const std::string &target_device, const int &api_version);

std::function<void()> read_cnnnetwork(const std::string &model, const int &api_version);

std::function<void()> cnnnetwork_reshape_batch_x2(const std::string &model, const int &iter, const int &api_version);

std::function<void()> set_input_params(const std::string &model, const int &api_version);

std::function<void()>
create_compiled_model(const std::string &model, const std::string &target_device, const int &api_version);

std::function<void()>
create_infer_request(const std::string &model, const std::string &target_device, const int &api_version);

std::function<void()>
infer_request_inference(const std::string &model, const std::string &target_device, const int &api_version);

std::function<void()>
inference_with_streams(const std::string &model, const std::string &target_device, const int &nstreams,
                       const int &api_version);

std::function<void()>
recreate_compiled_model(std::shared_ptr<InferApiBase> &ie, const std::string &model, const std::string &target_device,
                        const int &api_version);

std::function<void()> recreate_infer_request(std::shared_ptr<InferApiBase> &ie_wrapper);

std::function<void()> reinfer_request_inference(std::shared_ptr<InferApiBase> &ie_wrapper);