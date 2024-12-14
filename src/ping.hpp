#pragma once

#include <string>
#include <string_view>

#include <userver/components/component_list.hpp>

namespace service_template {

void AppendPing(userver::components::ComponentList &component_list);

} // namespace service_template
