#include "stat.hpp"
#include "ping.hpp"

#include <fmt/format.h>

#include <userver/components/component.hpp>
#include <userver/server/handlers/http_handler_base.hpp>

namespace service_template {

namespace {

class Stat final : public userver::server::handlers::HttpHandlerBase {
public:
  static constexpr std::string_view kName = "handler-v1-stat";

  Stat(const userver::components::ComponentConfig& config,
        const userver::components::ComponentContext& component_context)
      : HttpHandlerBase(config, component_context),
        component_context_(component_context) {}

  using HttpHandlerBase::HttpHandlerBase;

  std::string HandleRequestThrow(
      const userver::server::http::HttpRequest &request,
      userver::server::request::RequestContext&) const override {

    auto couter = 
            component_context_
                .FindComponent<Ping>("handler-v1-ping").counter_;

    return std::to_string(couter);
  }

  const userver::components::ComponentContext& component_context_;
};

} // namespace

void AppendStat(userver::components::ComponentList &component_list) {
  component_list.Append<Stat>();
}

} // namespace service_template
