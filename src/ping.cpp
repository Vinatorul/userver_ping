#include "ping.hpp"

#include <fmt/format.h>

#include <userver/server/handlers/http_handler_base.hpp>

namespace service_template {
  
std::string Ping::HandleRequestThrow(
      const userver::server::http::HttpRequest &request,
      userver::server::request::RequestContext &) const override {
    
    counter_++;

    return std::to_string(counter_);
  }

void AppendPing(userver::components::ComponentList &component_list) {
  component_list.Append<Ping>();
}

} // namespace service_template
