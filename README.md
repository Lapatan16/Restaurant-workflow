# Restaurant-workflow

This is a project made in C++ as part of a university project on the Faculty of Science on the University of Kragujevac.

Firstly you need to install cmake
1. sudo apt install cmake

Run the application with these commands:
1. cd build
2. cmake .
3. make
4. ./exe

This consol application simulates the workflow between the waiters and the customers in a restarant.

Multiple waiters can be created to work at different tables.
Customers come into the restaurant and get served with a table.
Waiters have the option of showing the customers the menu.

![Screenshot from 2024-07-11 17-57-15](https://github.com/user-attachments/assets/c2bc14ec-706a-4d82-8398-1e0e909a467e)

There is a daily menu which is generated for every hour. The generator uses a real-time seed to generate 3 dishes for a particular hour.

![Screenshot from 2024-07-11 17-57-58](https://github.com/user-attachments/assets/f4def3b6-e1e4-4a06-a442-58f7f55d5ff5)

The customer chooses what he wants to order, and the waiter brings him that.

![Screenshot from 2024-07-11 17-58-55](https://github.com/user-attachments/assets/046b4f30-cc21-4110-95e0-7f963e1861e0)

After the customer finishes his meal he can request the bill and pay for it. If he doesn't have enoght money on his balance then he can't leave the table untill the bill has been payed.

![Screenshot from 2024-07-11 17-59-46](https://github.com/user-attachments/assets/7dc4f755-c738-41fb-aa26-b5ae619ec8da)

The UML will explain more how all the classes interact with each other.

![UML](https://github.com/user-attachments/assets/b732f089-2239-4319-a54f-0f8068cd7957)
