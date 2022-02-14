#include <iostream>

#include "json_reader.h"
#include "map_renderer.h"
#include "request_handler.h"
#include "transport_catalogue.h"

using namespace std;
int main() {
    // freopen("../input.json","r", stdin);
    // freopen("../output.json","w", stdout);
    // freopen("../s10_final_opentest/s10_final_opentest_1.json","r", stdin);
    // freopen("../s10_final_opentest/s10_final_opentest_1_answer_my.json","2", stdout);
    transport_catalogue::TransportCatalogue transport_catalogue;  //Создаем каталог
    renderer::MapRenderer map_renderer;                           //Создаем рендерер

    json_reader::JsonReader json_reader(cin);
    json_reader.FillDataBase(transport_catalogue);  //Заполняем транспортный каталог

    renderer::RenderSettings render_setting = json_reader.GetRenderSettings();  //Получаем настройки для рендера из json файла
    map_renderer.SetRenderSettings(render_setting);

    RequestHandler request_handler = RequestHandler(transport_catalogue, map_renderer);

    json_reader.Out(transport_catalogue, request_handler, cout);  //Получаем JSON массив и выводим его в нужный потомк

    return 0;
}