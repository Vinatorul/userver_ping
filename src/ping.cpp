#include "ping.hpp"

#include <fmt/format.h>

#include <userver/server/handlers/http_handler_base.hpp>

namespace service_template {

namespace {

class Ping final : public userver::server::handlers::HttpHandlerBase {
public:
  static constexpr std::string_view kName = "handler-v1-ping";

  using HttpHandlerBase::HttpHandlerBase;

  std::string HandleRequestThrow(
      const userver::server::http::HttpRequest &request,
      userver::server::request::RequestContext &) const override {
    
    counter_++;

    return std::to_string(counter_);
  }

  mutable std::atomic<int> counter_ = 0;
};

} // namespace

void AppendPing(userver::components::ComponentList &component_list) {
  component_list.Append<Ping>();
}

} // namespace service_template
