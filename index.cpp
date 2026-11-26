    {
        cout << "\n===== CAR DEALERSHIP SYSTEM =====\n";
        cout << "1. Add Vehicle\n";
        cout << "2. Display Vehicles\n";
        cout << "3. Search Vehicle\n";
        cout << "4. Sort By Price\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";

        while (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        switch (choice)
        {
            case 1:
            {
                Car car;

                cout << "Enter Make: ";
                cin >> car.make;

                cout << "Enter Model: ";
                cin >> car.model;

                cout << "Enter Year: ";
                cin >> car.year;

                cout << "Enter Price: ";
                cin >> car.price;

                inventory.push_back(car);
                root = insert(root, car);

                cout << "Vehicle Added Successfully!\n";
                break;
            }

            case 2:
            {
                cout << "\nVehicle Inventory:\n";
                displayCars(root);
                break;
            }

            case 3:
            {
                string model;

                cout << "Enter Model To Search: ";
                cin >> model;

                Node* result = search(root, model);

                if (result != nullptr)
                {
                    cout << "\nVehicle Found:\n";
                    cout << result->car.make << " "
                         << result->car.model << " "
                         << result->car.year << " $"
                         << result->car.price << endl;
                }
                else
                {
                    cout << "Vehicle Not Found.\n";
                }

                break;
            }

            case 4:
            {
                insertionSort(inventory);

                cout << "\nVehicles Sorted By Price:\n";

                for (Car car : inventory)
                {
                    cout << car.make << " "
                         << car.model << " "
                         << car.year << " $"
                         << car.price << endl;
                }

                break;
            }

            case 5:
            {
                cout << "Goodbye!\n";
                break;
            }

            default:
            {
                cout << "Invalid Choice.\n";
            }
        }

    } while (choice != 5);

    return 0;
}
