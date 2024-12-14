#pragma once

#include <string>
#include <string_view>

#include <userver/components/component_list.hpp>
#include <userver/server/handlers/http_handler_base.hpp>

namespace service_template {

class Ping final : public userver::server::handlers::HttpHandlerBase {
public:
  static constexpr std::string_view kName = "handler-v1-ping";

  Ping(const userver::components::ComponentConfig& config,
        const userver::components::ComponentContext& component_context) {}

  using HttpHandlerBase::HttpHandlerBase;

  std::string HandleRequestThrow(
      const userver::server::http::HttpRequest &request,
      userver::server::request::RequestContext &) const override;

  mutable std::atomic<int> counter_ = 0;
};

void AppendPing(userver::components::ComponentList &component_list);

} // namespace service_template
