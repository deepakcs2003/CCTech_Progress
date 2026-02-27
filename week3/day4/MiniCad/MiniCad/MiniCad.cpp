#include <iostream>
#include <memory>
#include "ShapeManager.h"
#include "Circle.h"
#include "Triangle.h"
#include "Line.h"
#include "Point.h"

using namespace std;

int main()
{
    ShapeManager manager;
    int nextId = 1;   
    int choice;

    cout << "===== MiniCAD Geometry Engine =====\n";

    while (true)
    {
        try
        {
            cout << "\nMenu:\n";
            cout << "1. Create Circle\n";
            cout << "2. Create Triangle\n";
            cout << "3. Create Line\n";
            cout << "4. Display All Objects\n";
            cout << "5. Move Object\n";
            cout << "6. Scale Object\n";
            cout << "7. Delete Object\n";
            cout << "8. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            if (!cin)
                throw runtime_error("Invalid input");

            if (choice == 1)
            {
                double x, y, r;
                cout << "Enter center (x y): ";
                cin >> x >> y;
                cout << "Enter radius: ";
                cin >> r;

                manager.addObject(
                    make_unique<Circle>(nextId++, x, y, r)
                );

                cout << "Circle Created Successfully\n";
            }
            else if (choice == 2)
            {
                double x1, y1, x2, y2, x3, y3;
                cout << "Enter Point 1 (x1 y1): ";
                cin >> x1 >> y1;
                cout << "Enter Point 2 (x2 y2): ";
                cin >> x2 >> y2;
                cout << "Enter Point 3 (x3 y3): ";
                cin >> x3 >> y3;

                manager.addObject(
                    make_unique<Triangle>(nextId++,
                        x1, y1,
                        x2, y2,
                        x3, y3)
                );

                cout << "Triangle Created Successfully\n";
            }
            else if (choice == 3)
            {
                double x1, y1, x2, y2;
                cout << "Enter first point (x1 y1): ";
                cin >> x1 >> y1;
                cout << "Enter second point (x2 y2): ";
                cin >> x2 >> y2;

                manager.addObject(
                    make_unique<Line>(nextId++, x1, y1, x2, y2)
                );

                cout << "Line Created Successfully\n";
            }
            else if (choice == 4)
            {
                manager.displayAll();
            }
            else if (choice == 5)
            {
                int id;
                double dx, dy;
                cout << "Enter Object ID: ";
                cin >> id;
                cout << "Enter move dx dy: ";
                cin >> dx >> dy;

                manager.moveObject(id, dx, dy);
                cout << "Object moved successfully\n";
            }
            else if (choice == 6)
            {
                int id;
                double factor;
                cout << "Enter Object ID: ";
                cin >> id;
                cout << "Enter scale factor: ";
                cin >> factor;

                manager.scaleObject(id, factor);
                cout << "Object scaled successfully\n";
            }
            else if (choice == 7)
            {
                int id;
                cout << "Enter Object ID: ";
                cin >> id;

                manager.deleteObject(id);
                cout << "Object deleted successfully\n";
            }
            else if (choice == 8)
            {
                cout << "Exiting Program...\n";
                break;
            }
            else
            {
                cout << "Invalid Choice\n";
            }
        }
        catch (const exception& e)
        {
            cout << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    return 0;
}