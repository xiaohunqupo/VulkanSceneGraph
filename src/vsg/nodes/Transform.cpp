/* <editor-fold desc="MIT License">

Copyright(c) 2018 Robert Osfield

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

</editor-fold> */

#include <vsg/core/compare.h>
#include <vsg/io/stream.h>
#include <vsg/nodes/Transform.h>

using namespace vsg;

Transform::Transform()
{
}

Transform::Transform(const Transform& rhs, const CopyOp& copyop) :
    Inherit(rhs, copyop),
    subgraphRequiresLocalFrustum(rhs.subgraphRequiresLocalFrustum)
{
}

int Transform::compare(const Object& rhs_object) const
{
    int result = Group::compare(rhs_object);
    if (result != 0) return result;

    const auto& rhs = static_cast<decltype(*this)>(rhs_object);
    return compare_value(subgraphRequiresLocalFrustum, rhs.subgraphRequiresLocalFrustum);
}

void Transform::read(Input& input)
{
    Group::read(input);
}

void Transform::write(Output& output) const
{
    Group::write(output);
}
