#include "romb.h"
#include <iostream>

using namespace std;

int main() {
    cout << "--- Diamond Inheritance (Clothing) ---" << endl;
    Clothing myClothing("Red", "L");
    myClothing.Describe();
    myClothing.Display();
    cout << endl;

    cout << "--- Multiple Inheritance (DesignerShirt) ---" << endl;
    DesignerShirt myShirt("White", "S", "Nike");
    myShirt.Describe();
    myShirt.Display();
    cout << endl;

    cout << "--- Multiple Inheritance (CasualJacket) ---" << endl;
    CasualJacket myJacket("Green", "M", true);
    myJacket.Describe();
    myJacket.Display();
    cout << endl;

    cout << "--- Inheritance from Three Parent Classes ---" << endl;
    MultiFeatureItem myItem("Black", "M", "Shiny");
    myItem.Describe();
    cout << endl;

    return 0;
}