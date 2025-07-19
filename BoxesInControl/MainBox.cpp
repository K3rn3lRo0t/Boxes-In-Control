#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Boxes {
public:
    double length;
    double width;
    double depth;
    string material;
    string SuitableForFood;
    string name;
};

int ForCycle = 0;
int forChecking;
vector<Boxes> AllBoxes;

int main() {
    cout << "----------------------" << endl;
    cout << "1 - Add a box (max 10)" << endl;
    cout << "2 - View all boxes" << endl;
    cout << "0 - Exit the program" << endl;
    
    while (ForCycle == 0) {
        cout << "----------------------" << endl;
        cout << "Write A Number: ";
        cin >> forChecking;
        if (forChecking == 1) {
            Boxes newBox;
            cout << "Length: ";
            cin >> newBox.length;
            cout << "Width: ";
            cin >> newBox.width;
            cout << "Depth: ";
            cin >> newBox.depth;
            cout << "Material: " << endl;
            cin >> newBox.material;
            cout << "Suitable For Food: " << endl;
            cin >> newBox.SuitableForFood;
            cout << "Box Name: ";
            cin >> newBox.name;
            AllBoxes.push_back(newBox);
            continue;
        } else if (forChecking == 2) {
            if (AllBoxes.size() == 0) {
                cout << "No Boxes Added Yet!" << endl;
                continue;
            } else {
                cout << "List Of All Boxes: " << endl;
                for (int i = 0; i < AllBoxes.size(); ++i) cout << i+1 << ") " << "Box: " << AllBoxes[i].name << endl;
            } 
        } else if (forChecking == 0) {
            ForCycle = 1;
        } else {
            cout << "Write A Valid Number!" << endl;
            continue;
        }
    }
}