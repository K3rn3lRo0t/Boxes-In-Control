#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

class Box {
public:
    int id;
    double length;
    double width;
    double depth;
    string material;
    string suitableForFood;
    string name;
};

void displayMenu();
void addBox(unordered_map<int, Box>& boxes, int& nextId);
void viewAllBoxes(const unordered_map<int, Box>& boxes);
void receiveBox(const unordered_map<int, Box>& boxes);
void removeBox(unordered_map<int, Box>& boxes);
void updateAllParameters(unordered_map<int, Box>& boxes);
void updateSpecificParameter(unordered_map<int, Box>& boxes);

int main() {
    unordered_map<int, Box> boxes;
    int nextId = 1;
    bool isRunning = true;

    while (isRunning) {
        displayMenu();

        int userChoice;
        cout << "Write a number: ";
        cin >> userChoice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (userChoice) {
        case 0:
            isRunning = false;
            break;
        case 1:
            addBox(boxes, nextId);
            break;
        case 2:
            viewAllBoxes(boxes);
            break;
        case 3:
            receiveBox(boxes);
            break;
        case 4:
            removeBox(boxes);
            break;
        case 5:
            updateAllParameters(boxes);
            break;
        case 6:
            updateSpecificParameter(boxes);
            break;
        default:
            cout << "Write a valid number!" << endl;
            break;
        }
    }

    return 0;
}

void displayMenu() {
    cout << "----------------------" << endl;
    cout << "0 - Exit the program" << endl;
    cout << "1 - Add a box (max 10)" << endl;
    cout << "2 - View all boxes" << endl;
    cout << "3 - Receive the box" << endl;
    cout << "4 - Remove the box" << endl;
    cout << "5 - Update all box parameters" << endl;
    cout << "6 - Update a specific parameter" << endl;
    cout << "----------------------" << endl;
}

void addBox(unordered_map<int, Box>& boxes, int& nextId) {
    if (boxes.size() >= 10) {
        cout << "Maximum limit reached (10 boxes)!" << endl;
        return;
    }

    Box newBox;
    newBox.id = nextId++;

    cout << "Length: ";
    cin >> newBox.length;

    cout << "Width: ";
    cin >> newBox.width;

    cout << "Depth: ";
    cin >> newBox.depth;

    cout << "Material: ";
    cin >> newBox.material;

    cout << "Suitable for food (yes/no): ";
    cin >> newBox.suitableForFood;

    cout << "Box name: ";
    cin >> newBox.name;

    boxes[newBox.id] = newBox;
    cout << "Box added successfully with ID: " << newBox.id << endl;
}

void viewAllBoxes(const unordered_map<int, Box>& boxes) {
    if (boxes.empty()) {
        cout << "No boxes added yet!" << endl;
        return;
    }

    cout << "List of all boxes:" << endl;
    for (const auto& pair : boxes) {
        cout << "ID: " << pair.first << " | Name: " << pair.second.name << endl;
    }
}

void receiveBox(const unordered_map<int, Box>& boxes) {
    if (boxes.empty()) {
        cout << "There are no boxes to receive!" << endl;
        return;
    }

    viewAllBoxes(boxes);

    int boxId;
    cout << "Enter the ID of the box you want to receive: ";
    cin >> boxId;

    auto it = boxes.find(boxId);
    if (it == boxes.end()) {
        cout << "Box with ID " << boxId << " not found!" << endl;
        return;
    }

    const Box& box = it->second;
    cout << "-----------------------------------" << endl;
    cout << "Parameters of the box you received:" << endl;
    cout << "ID: " << box.id << endl;
    cout << "Name: " << box.name << endl;
    cout << "Length: " << box.length << endl;
    cout << "Width: " << box.width << endl;
    cout << "Depth: " << box.depth << endl;
    cout << "Material: " << box.material << endl;
    cout << "Suitable for food: " << box.suitableForFood << endl;
}

void removeBox(unordered_map<int, Box>& boxes) {
    if (boxes.empty()) {
        cout << "Nothing to remove!" << endl;
        return;
    }

    viewAllBoxes(boxes);

    int boxId;
    cout << "Enter the ID of the box you want to remove: ";
    cin >> boxId;

    if (boxes.erase(boxId)) {
        cout << "Box with ID " << boxId << " has been successfully removed!" << endl;
    }
    else {
        cout << "Box with ID " << boxId << " not found!" << endl;
    }
}

void updateAllParameters(unordered_map<int, Box>& boxes) {
    if (boxes.empty()) {
        cout << "Nothing to update!" << endl;
        return;
    }

    viewAllBoxes(boxes);

    int boxId;
    cout << "Enter the ID of the box you want to update: ";
    cin >> boxId;

    auto it = boxes.find(boxId);
    if (it == boxes.end()) {
        cout << "Box with ID " << boxId << " not found!" << endl;
        return;
    }

    Box& box = it->second;
    cout << "Enter new name: ";
    cin >> box.name;

    cout << "Enter new length: ";
    cin >> box.length;

    cout << "Enter new width: ";
    cin >> box.width;

    cout << "Enter new depth: ";
    cin >> box.depth;

    cout << "Enter new material: ";
    cin >> box.material;

    cout << "Enter new suitable for food (yes/no): ";
    cin >> box.suitableForFood;

    cout << "All parameters have been successfully updated for box ID: " << box.id << endl;
}

void updateSpecificParameter(unordered_map<int, Box>& boxes) {
    if (boxes.empty()) {
        cout << "Nothing to update!" << endl;
        return;
    }

    viewAllBoxes(boxes);

    int boxId;
    cout << "Enter the ID of the box you want to update: ";
    cin >> boxId;

    auto it = boxes.find(boxId);
    if (it == boxes.end()) {
        cout << "Box with ID " << boxId << " not found!" << endl;
        return;
    }

    Box& box = it->second;

    cout << "Select the parameter to update:" << endl;
    cout << "1) Name: " << box.name << endl;
    cout << "2) Length: " << box.length << endl;
    cout << "3) Width: " << box.width << endl;
    cout << "4) Depth: " << box.depth << endl;
    cout << "5) Material: " << box.material << endl;
    cout << "6) Suitable for food: " << box.suitableForFood << endl;

    int parameterChoice;
    cout << "Enter parameter number to update: ";
    cin >> parameterChoice;

    switch (parameterChoice) {
    case 1:
        cout << "Enter new name: ";
        cin >> box.name;
        break;
    case 2:
        cout << "Enter new length: ";
        cin >> box.length;
        break;
    case 3:
        cout << "Enter new width: ";
        cin >> box.width;
        break;
    case 4:
        cout << "Enter new depth: ";
        cin >> box.depth;
        break;
    case 5:
        cout << "Enter new material: ";
        cin >> box.material;
        break;
    case 6:
        cout << "Enter new suitable for food (yes/no): ";
        cin >> box.suitableForFood;
        break;
    default:
        cout << "Invalid parameter choice!" << endl;
        return;
    }

    cout << "Parameter updated successfully for box ID: " << box.id << endl;
}