// Copyright (C) 2018-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <ngraph/op/op.hpp>

namespace ngraph {
namespace snippets {
namespace op {

/**
 * @interface Load
 * @brief Generated by Canonicalization step where explicit instructions should be emitted for data loading
 *        where number of elements to load is determined by "count"
 *        Default value is "1" - to load one element
 * @ingroup snippets
 */
class Load : public ngraph::op::Op {
public:
    OPENVINO_OP("Load", "SnippetsOpset");

    Load(const Output<Node>& x, const size_t count = 1lu);
    Load() = default;

    size_t get_count() const { return m_count; }

    void set_count(const size_t count) { m_count = count; }

    bool visit_attributes(AttributeVisitor& visitor) override;

    std::shared_ptr<Node> clone_with_new_inputs(const OutputVector& new_args) const override;

    void validate_and_infer_types() override;

    OPENVINO_SUPPRESS_DEPRECATED_START
    bool evaluate(const HostTensorVector& output_values, const HostTensorVector& input_values) const override;
    OPENVINO_SUPPRESS_DEPRECATED_END

protected:
    size_t m_count = 0lu;
};

} // namespace op
} // namespace snippets
} // namespace ngraph