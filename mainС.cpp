#include "clothing.h"

int main() {
    Shirt myShirt("Blue", "M", "Cotton");
    Pants myPants("Black", "L", "Denim"); //�����
    Jacket myJacket("Red", "XL", "Leather");//����
    DesignerShirt myDesignerShirt("White", "S", "Silk", "Nike");
    CasualJacket myCasualJacket("Green", "M", "Polyester", true);

    myShirt.Describe();
    myPants.Describe();
    myJacket.Describe();
    myDesignerShirt.Describe();
    myCasualJacket.Describe();

    return 0;
}