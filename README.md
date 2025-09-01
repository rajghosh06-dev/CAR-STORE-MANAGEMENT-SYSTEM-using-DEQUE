# Car Store Management System using Deque (C Language)

## Project Overview
This is a menu-driven C program that simulates a car store inventory system using a **Double Ended Queue (Deque)**. It allows efficient management of car stock arrivals, urgent priority additions, and sales from both ends of the queue.

The system supports:
- Adding new cars (rear for regular arrivals, front for urgent priority)
- Selling cars (front for oldest stock, rear for latest arrivals)
- Searching and displaying car details
- Clearing the entire inventory

---

## 🛠️ Features

### Menu Options:
1. Add a new car at the rear (new stock arrival)  
2. Add a priority car at the front (urgent stock)  
3. Sell a car from the front (old stock sold)  
4. Sell a car from the rear (latest stock sold)  
5. Search for a car and display its details  
6. Display all cars in tabular format  
7. Delete all cars from the store  
8. Exit the application  

---

## 📦 Car Details Stored
Each car entry includes:
- **Model Name**  
- **Model Year (YYYY)**  
- **Brand**  
- **Fuel Type**  
- **Priority Level**

---

## Data Structure Used
- **Double Ended Queue (Deque)** implemented using linked lists or arrays.
- Allows insertion and deletion from both ends for flexible inventory control.

---

## How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/car-store-deque.git
   cd car-store-deque
   ```

2. Compile the program:
   ```bash
   gcc car_store.c -o car_store
   ```

3. Run the executable:
   ```bash
   ./car_store
   ```

---

## 📈 Future Enhancements
- Save/load inventory to/from a file
- GUI interface using GTK or ncurses
- Sorting cars by year or brand
- Priority-based selling logic

---

## 👨‍💻 Author
Rishit — passionate about system-level design, modular workflows, and technical clarity.

---

## 📄 License
This project is open-source and available under the MIT License.
