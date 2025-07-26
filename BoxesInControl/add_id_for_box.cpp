#include <iostream>
#include <vector>
#include <string>
#include <limits>

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

void printBoxParameters(const Boxes& box) {
    cout << "-----------------------------------" << endl;
    cout << "Parameters of the box:" << endl;
    cout << "Box Name: " << box.name << endl;
    cout << "Length: " << box.length << endl;
    cout << "Width: " << box.width << endl;
    cout << "Depth: " << box.depth << endl;
    cout << "Material: " << box.material << endl;
    cout << "Suitable For Food: " << box.SuitableForFood << endl;
}

double getPositiveNumber(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (value <= 0) {
            cout << "Value must be positive!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore();
            return value;
        }
    }
}

int main() {
    int ForCycle = 0;
    int forChecking;
    int forBoxList;
    int forParameterList;
    vector<Boxes> AllBoxes;

    while (ForCycle == 0) {
        cout << "----------------------" << endl;
        cout << "0 - Exit the program" << endl;
        cout << "1 - Add a box (max 10)" << endl;
        cout << "2 - View all boxes" << endl;
        cout << "3 - View box details" << endl;
        cout << "4 - Remove a box" << endl;
        cout << "5 - Update all box parameters" << endl;
        cout << "6 - Update a specific parameter" << endl;
        cout << "----------------------" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> forChecking)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

        if (forChecking == 0) {
            ForCycle = 1;
            cout << "Exiting program..." << endl;
        }
        else if (forChecking == 1) {
            if (AllBoxes.size() >= 10) {
                cout << "The box limit has been reached (max 10 boxes)!" << endl;
                continue;
            }

            Boxes newBox;
            newBox.length = getPositiveNumber("Length: ");
            newBox.width = getPositiveNumber("Width: ");
            newBox.depth = getPositiveNumber("Depth: ");

            cout << "Material: ";
            getline(cin, newBox.material);

            do {
                cout << "Suitable For Food (yes/no): ";
                getline(cin, newBox.SuitableForFood);
            } while (newBox.SuitableForFood != "yes" && newBox.SuitableForFood != "no");

            cout << "Box Name: ";
            getline(cin, newBox.name);

            AllBoxes.push_back(newBox);
            cout << "Box added successfully!" << endl;
        }
        else if (forChecking == 2) {
            if (AllBoxes.empty()) {
                cout << "No boxes added yet!" << endl;
                continue;
            }

            cout << "List of all boxes: " << endl;
            for (int i = 0; i < AllBoxes.size(); ++i) {
                cout << i + 1 << ") " << AllBoxes[i].name << endl;
            }
        }
        else if (forChecking == 3) {
            if (AllBoxes.empty()) {
                cout << "There are no boxes to view!" << endl;
                continue;
            }

            cout << "Select a box to view details: " << endl;
            for (int i = 0; i < AllBoxes.size(); ++i) {
                cout << i + 1 << ") " << AllBoxes[i].name << endl;
            }

            cout << "Enter box number: ";
            if (!(cin >> forBoxList)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number." << endl;
                continue;
            }

            if (forBoxList < 1 || forBoxList > AllBoxes.size()) {
                cout << "Invalid box number!" << endl;
            }
            else {
                printBoxParameters(AllBoxes[forBoxList - 1]);
            }
        }
        else if (forChecking == 4) {
            if (AllBoxes.empty()) {
                cout << "No boxes to remove!" << endl;
                continue;
            }

            cout << "Select a box to remove: " << endl;
            for (int i = 0; i < AllBoxes.size(); ++i) {
                cout << i + 1 << ") " << AllBoxes[i].name << endl;
            }

            cout << "Enter box number: ";
            if (!(cin >> forBoxList)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number." << endl;
                continue;
            }

            if (forBoxList < 1 || forBoxList > AllBoxes.size()) {
                cout << "Invalid box number!" << endl;
            }
            else {
                AllBoxes.erase(AllBoxes.begin() + (forBoxList - 1));
                cout << "Box removed successfully!" << endl;
            }
        }
        else if (forChecking == 5) {
            if (AllBoxes.empty()) {
                cout << "No boxes to update!" << endl;
                continue;
            }

            cout << "Select a box to update: " << endl;
            for (int i = 0; i < AllBoxes.size(); ++i) {
                cout << i + 1 << ") " << AllBoxes[i].name << endl;
            }

            cout << "Enter box number: ";
            if (!(cin >> forBoxList)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number." << endl;
                continue;
            }

            if (forBoxList < 1 || forBoxList > AllBoxes.size()) {
                cout << "Invalid box number!" << endl;
            }
            else {
                Boxes& box = AllBoxes[forBoxList - 1];
                box.length = getPositiveNumber("New Length: ");
                box.width = getPositiveNumber("New Width: ");
                box.depth = getPositiveNumber("New Depth: ");

                cout << "New Material: ";
                cin.ignore();
                getline(cin, box.material);

                do {
                    cout << "New Suitable For Food (yes/no): ";
                    getline(cin, box.SuitableForFood);
                } while (box.SuitableForFood != "yes" && box.SuitableForFood != "no");

                cout << "New Box Name: ";
                getline(cin, box.name);

                cout << "Box updated successfully!" << endl;
            }
        }
        else if (forChecking == 6) {
            if (AllBoxes.empty()) {
                cout << "No boxes to update!" << endl;
                continue;
            }

            cout << "Select a box to update: " << endl;
            for (int i = 0; i < AllBoxes.size(); ++i) {
                cout << i + 1 << ") " << AllBoxes[i].name << endl;
            }

            cout << "Enter box number: ";
            if (!(cin >> forBoxList)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number." << endl;
                continue;
            }

            if (forBoxList < 1 || forBoxList > AllBoxes.size()) {
                cout << "Invalid box number!" << endl;
                continue;
            }

            Boxes& box = AllBoxes[forBoxList - 1];
            cout << "Select parameter to update: " << endl;
            cout << "1) Name: " << box.name << endl;
            cout << "2) Length: " << box.length << endl;
            cout << "3) Width: " << box.width << endl;
            cout << "4) Depth: " << box.depth << endl;
            cout << "5) Material: " << box.material << endl;
            cout << "6) Suitable For Food: " << box.SuitableForFood << endl;

            cout << "Enter parameter number: ";
            if (!(cin >> forParameterList)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number." << endl;
                continue;
            }

            if (forParameterList < 1 || forParameterList > 6) {
                cout << "Invalid parameter number!" << endl;
                continue;
            }

            cin.ignore();
            switch (forParameterList) {
            case 1:
                cout << "Enter new name: ";
                getline(cin, box.name);
                break;
            case 2:
                box.length = getPositiveNumber("Enter new length: ");
                break;
            case 3:
                box.width = getPositiveNumber("Enter new width: ");
                break;
            case 4:
                box.depth = getPositiveNumber("Enter new depth: ");
                break;
            case 5:
                cout << "Enter new material: ";
                getline(cin, box.material);
                break;
            case 6:
                do {
                    cout << "Enter new Suitable For Food (yes/no): ";
                    getline(cin, box.SuitableForFood);
                } while (box.SuitableForFood != "yes" && box.SuitableForFood != "no");
                break;
            }

            cout << "Parameter updated successfully!" << endl;
        }
        else {
            cout << "Invalid choice! Please enter a number between 0 and 6." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}