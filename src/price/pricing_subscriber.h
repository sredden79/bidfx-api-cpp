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

#ifndef PUBLIC_API_CPP_PRICE_PRICING_SUBSCRIBER_H_
#define PUBLIC_API_CPP_PRICE_PRICING_SUBSCRIBER_H_

#include "include/bulk_subscriber.h"
#include "include/price/subject/subject.h"
#include "pricing_session.h"

namespace bidfx_public_api::price
{

using bidfx_public_api::price::subject::Subject;

class PricingSession;

/**
 * @author Frazer Bennett Wilford
 */
class PricingSubscriber : public BulkSubscriber
{
private:
    SubjectFactory subjects_;
    PricingSession* session_;
    UserInfo* user_info_;

public:
    PricingSubscriber(PricingSession* session, UserInfo* user_info);

    void Subscribe(Subject subject, bool refresh) override;
    void Subscribe(Subject subject) override;
    void Unsubscribe(Subject& subject) override;

    void UnsubscribeAll() override;
    void ResubscribeAll() override;

    SubjectFactory Subjects() override;
};

}

#endif //PUBLIC_API_CPP_PRICE_PRICING_SUBSCRIBER_H_
