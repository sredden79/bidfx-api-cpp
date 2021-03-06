/**  Copyright 2019 BidFX

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

            http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
 */

#include "heartbeat_message.h"
#include "pixie_message_type.h"

namespace bidfx_public_api::price::pixie
{

HeartbeatMessage::HeartbeatMessage()
{
}

ByteBuffer HeartbeatMessage::Encode(int version) const
{
    ByteBuffer buffer(1);
    buffer.WriteByte(PixieMessageType::HEARTBEAT);
    return std::move(buffer);
}

const std::string HeartbeatMessage::ToString()
{
    return "Heartbeat()";
}

const bool HeartbeatMessage::operator==(const PixieMessage &other) const
{
    return dynamic_cast<const HeartbeatMessage*>(&other) != nullptr;
}

const bool HeartbeatMessage::operator!=(const PixieMessage &other) const
{
    return !this->operator==(other);
}

}

