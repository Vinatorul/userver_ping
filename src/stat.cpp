#include "stat.hpp"
#include "ping.hpp"

#include <fmt/format.h>

#include <userver/server/handlers/http_handler_base.hpp>

namespace service_template {

namespace {

class Stat final : public userver::server::handlers::HttpHandlerBase {
public:
  static constexpr std::string_view kName = "handler-v1-stat";

  Hello(const userver::components::ComponentConfig& config,
        const userver::components::ComponentContext& component_context)
      : HttpHandlerBase(config, component_context),
        ping_component_(
            component_context
                .FindComponent<userver::components::Postgres>("handler-v1-ping")) {}

  using HttpHandlerBase::HttpHandlerBase;

  std::string HandleRequestThrow(
      const userver::server::http::HttpRequest &request,
      userver::server::request::RequestContext&) const override {
    return std::to_string(ping_component_.counter_);
  }

  Ping ping_component_;
};

} // namespace

void AppendStat(userver::components::ComponentList &component_list) {
  component_list.Append<Stat>();
}

} // namespace service_template