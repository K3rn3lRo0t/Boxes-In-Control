#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

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

int main() {
    int ForCycle = 0;
    int forChecking;
    int forBoxList;
    int forParameterList;
    vector<Boxes> AllBoxes;
    unordered_map<string, int> boxList;

    while (ForCycle == 0) {
        cout << "----------------------" << endl;
        cout << "0 - Exit the program" << endl;
        cout << "1 - Add a box (max 10)" << endl;
        cout << "2 - View all boxes" << endl;
        cout << "3 - Receiving the box" << endl;
        cout << "4 - Removing the box" << endl;
        cout << "5 - Updating all box parameters" << endl;
        cout << "6 - Updating a specific setting" << endl;
        cout << "----------------------" << endl;
        cout << "Write A Number: ";
        cin >> forChecking;

        if (forChecking == 0) {
            ForCycle = 1;
            continue;
        }
        else if (forChecking == 1) {
            if (AllBoxes.size() == 10) {
                cout << "Maximum Limit!" << endl;
                continue;
            }
            else {
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
            }
        }
        else if (forChecking == 2) {
            if (AllBoxes.size() == 0) {
                cout << "No Boxes Added Yet!" << endl;
                continue;
            }
            else {
                cout << "List Of All Boxes: " << endl;
                for (int i = 0; i < AllBoxes.size(); ++i) cout << i + 1 << ") " << "Box: " << AllBoxes[i].name << endl;
            }
        }
        else if (forChecking == 3) {
            if (AllBoxes.size() == 0) {
                cout << "There are no boxes that can be received!" << endl;
            }
            else {
                cout << "Select the box you want to receive: " << endl;
                for (int i = 0; i < AllBoxes.size(); ++i) cout << i + 1 << ") " << "Box: " << AllBoxes[i].name << endl;
                cout << "Select a number from the list: ";
                cin >> forBoxList;
                if ((forBoxList > AllBoxes.size()) or (forBoxList <= 0)) {
                    cout << "Choose a number from the list, not a random one!" << endl;
                }
                else {
                    cout << "-----------------------------------" << endl;
                    cout << "Parameters of the box you received:" << endl;
                    cout << "Box Name: " << AllBoxes[forBoxList - 1].name << endl;
                    cout << "Length: " << AllBoxes[forBoxList - 1].length << endl;
                    cout << "Width: " << AllBoxes[forBoxList - 1].width << endl;
                    cout << "Depth: " << AllBoxes[forBoxList - 1].depth << endl;
                    cout << "Material: " << AllBoxes[forBoxList - 1].material << endl;
                    cout << "Suitable For Food: " << AllBoxes[forBoxList - 1].SuitableForFood << endl;
                }
            }
        }
        else if (forChecking == 4) {
            if (AllBoxes.size() == 0) {
                cout << "Nothing to remove!" << endl;
            }
            else {
                cout << "Select the box you want to remove: " << endl;
                for (int i = 0; i < AllBoxes.size(); ++i) cout << i + 1 << ") " << "Box: " << AllBoxes[i].name << endl;
                cout << "Select a number from the list: ";
                cin >> forBoxList;
                if ((forBoxList > AllBoxes.size()) or (forBoxList <= 0)) {
                    cout << "Choose a number from the list, not a random one!" << endl;
                }
                else {
                    AllBoxes.erase(AllBoxes.begin() + (forBoxList - 1));
                    cout << "The box has been successfully removed!" << endl;
                }
            }
        }
        else if (forChecking == 5) {
            if (AllBoxes.size() == 0) {
                cout << "Nothing to update!" << endl;
            }
            else {
                cout << "Select the box you want to update: " << endl;
                for (int i = 0; i < AllBoxes.size(); ++i) cout << i + 1 << ") " << "Box: " << AllBoxes[i].name << endl;
                cout << "Select a number from the list: ";
                cin >> forBoxList;
                if ((forBoxList > AllBoxes.size()) or (forBoxList <= 0)) {
                    cout << "Choose a number from the list, not a random one!" << endl;
                }
                else {
                    cout << "The number has been successfully received!" << endl;
                    cout << "Box Name: ";
                    cin >> AllBoxes[forBoxList - 1].name;
                    cout << "Length: ";
                    cin >> AllBoxes[forBoxList - 1].length;
                    cout << "Width: ";
                    cin >> AllBoxes[forBoxList - 1].width;
                    cout << "Depth: ";
                    cin >> AllBoxes[forBoxList - 1].depth;
                    cout << "Material: ";
                    cin >> AllBoxes[forBoxList - 1].material;
                    cout << "Suitable For Food: ";
                    cin >> AllBoxes[forBoxList - 1].SuitableForFood;
                    cout << "All parameters have been successfully updated!" << endl;
                }
            }
        }
        else if (forChecking == 6) {
            if (AllBoxes.size() == 0) {
                cout << "Nothing to update!" << endl;
            }
            else {
                cout << "Select the box you want to receive: " << endl;
                for (int i = 0; i < AllBoxes.size(); ++i) cout << i + 1 << ") " << "Box: " << AllBoxes[i].name << endl;
                cout << "Select a number from the list: ";
                cin >> forBoxList;
                if ((forBoxList > AllBoxes.size()) or (forBoxList <= 0)) {
                    cout << "Choose a number from the list, not a random one!" << endl;
                }
                else {
                    cout << "Select the parameter you want to receive: " << endl;
                    cout << "1) " << "Parameter Name: " << AllBoxes[forBoxList - 1].name << endl;
                    cout << "2) " << "Parameter Length: " << AllBoxes[forBoxList - 1].length << endl;
                    cout << "3) " << "Parameter Width: " << AllBoxes[forBoxList - 1].width << endl;
                    cout << "4) " << "Parameter Depth: " << AllBoxes[forBoxList - 1].depth << endl;
                    cout << "5) " << "Parameter Material: " << AllBoxes[forBoxList - 1].material << endl;
                    cout << "6) " << "Parameter SuitableForFood: " << AllBoxes[forBoxList - 1].SuitableForFood << endl;
                    cout << "Select a number from the list: ";
                    cin >> forParameterList;
                    if ((forParameterList < 1) or (forParameterList > 6)) {
                        cout << "Choose a number from the list, not a random one!" << endl;
                    }
                    else {
                        if (forParameterList == 1) {
                            cout << "Enter your changes: ";
                            cin >> AllBoxes[forBoxList - 1].name;
                            cout << "The changes were successful!" << endl;
                        }
                        else if (forParameterList == 2) {
                            cout << "Enter your changes: ";
                            cin >> AllBoxes[forBoxList - 1].length;
                            cout << "The changes were successful!" << endl;
                        }
                        else if (forParameterList == 3) {
                            cout << "Enter your changes: ";
                            cin >> AllBoxes[forBoxList - 1].width;
                            cout << "The changes were successful!" << endl;
                        }
                        else if (forParameterList == 4) {
                            cout << "Enter your changes: ";
                            cin >> AllBoxes[forBoxList - 1].depth;
                            cout << "The changes were successful!" << endl;
                        }
                        else if (forParameterList == 5) {
                            cout << "Enter your changes: ";
                            cin >> AllBoxes[forBoxList - 1].material;
                            cout << "The changes were successful!" << endl;
                        }
                        else if (forParameterList == 6) {
                            cout << "Enter your changes: ";
                            cin >> AllBoxes[forBoxList - 1].SuitableForFood;
                            cout << "The changes were successful!" << endl;
                        }
                        else {
                            cout << "Choose a number from the list, not a random one!" << endl;
                        }
                    }
                }
            }
        }
        else {
            cout << "Write A Valid Number!" << endl;
            continue;
        }
    }
}