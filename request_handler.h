#pragma once
#include <unordered_set>

#include "domain.h"
#include "map_renderer.h"
#include "transport_catalogue.h"

class RequestHandler {
   public:
    // MapRenderer понадобится в следующей части итогового проекта
    RequestHandler(const transport_catalogue::TransportCatalogue& db, const renderer::MapRenderer& renderer) : db_(db), renderer_(renderer){};

    // Возвращает информацию о маршруте (запрос Bus)
    std::optional<domain::BusStat> GetBusStat(const std::string& bus_name) const;

    // Возвращает маршруты, проходящие через
    std::set<std::string> GetBusesByStop(const std::string& stop_name) const;

    // Этот метод будет нужен в следующей части итогового проекта
    svg::Document RenderMap() const;

   private:
    // RequestHandler использует агрегацию объектов "Транспортный Справочник" и "Визуализатор Карты"
    const transport_catalogue::TransportCatalogue& db_;
    const renderer::MapRenderer& renderer_;
};
