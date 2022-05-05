#include "Tests/tests.h"
#include "UI/UI.h"

using namespace std;

int main() {
    testAll();
    RepoInFile repoInFile(R"(/Users/bogdanzarnescu/Desktop/Facultate-OOP/Lab-10-live/products.txt)");
    Money money;
    Service service(repoInFile, money);
    UI ui(service);
    ui.runMenu();
    return 0;
}
