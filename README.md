# Unit7Project-CloudComputing
Unit 7 project for cloud computing (IT320-7)

This project implements a fully functional, console‑based online shopping system written in C++. The system allows users to browse a product catalog, add items to their shopping cart, remove items, and complete purchases through a simulated checkout process. It also includes an administrative interface for managing the product catalog, a login system for both users and administrators, and a multithreading component that demonstrates concurrent access to shared resources. The design emphasizes modularity, object‑oriented programming principles, and safe handling of shared data through mutexes.

The application models a simplified version of a real‑world e‑commerce platform. Users can create accounts, log in, and interact with the system based on their assigned user type. The system supports Regular, Premium, and VIP users, each with different privileges and discount levels. Administrators have access to a separate menu that allows them to add and remove products from the catalog. Throughout the program, input validation ensures that invalid or unexpected user input does not cause crashes or undefined behavior. The project also demonstrates concurrency by simulating multiple users interacting with the catalog at the same time, with mutexes ensuring that stock quantities remain consistent.

This project includes an .exe format to run the program, and the project files used to complete this project.
