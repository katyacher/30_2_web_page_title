#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main(int, char**){
    std::cout << "Hello, from 30_2_web_page_title!\n";

    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),
                    cpr::Header({{"Accept", "text/html"}}));

    int title_begin = r.text.find("<h1>") + 4;
    int title_end = r.text.find("</h1>");

    for(int i = title_begin; i < title_end; i++){
        std::cout << r.text[i];
    }
    
    std::cout << std::endl;
    return 0;
}
