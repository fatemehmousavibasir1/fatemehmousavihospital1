# Hospital Management System

This C++ project is a hospital management system that allows managing patients and doctors, including functionalities like registering new patients and doctors, displaying their details, modifying their information, and deleting records.

## Features

- Register new patients and doctors.
- Display details of all patients and doctors.
- Modify patient and doctor information.
- Delete patient and doctor records.
- Register patients to doctors based on specialization.
- Save and load patient and doctor information from CSV files.

## Classes

### Person Class

The `Person` class serves as the base class for both `Patient` and `Doctor`. It contains attributes such as:

- Name
- Family
- Address
- Phone Number
- Age
- ID Number

The `Person` class has getter and setter functions for these attributes and a `report()` function to display the details of a person.

### Patient Class

The `Patient` class inherits from the `Person` class and adds a new attribute, `type`, which indicates the type of illness or medical condition. It overrides the `report()` function to include the patient's type.

### Doctor Class

The `Doctor` class inherits from `Person` and adds a `specialist` attribute to denote the medical field or specialty of the doctor. It overrides the `report()` function to display the doctor’s specialty along with other information.

## File Management

The program uses `fstream` to save and load patient and doctor information to and from CSV files (`patient.csv` and `docter.csv`). Patients and doctors are stored in vectors, and new data can be added, displayed, or modified.

## Managing Patients and Doctors

- **Register Patient:** `writep()` is used to add a new patient to the system.
- **Display All Patients:** `displayallp()` displays details of all patients.
- **Modify Patient:** `modify()` allows modifying the details of a patient using their ID number.
- **Delete Patient:** `delete_patient()` removes a patient from the system based on the ID number.
- **Register Doctor:** `writeDA()` is used to add a new doctor to the system.
- **Display All Doctors:** `displayalld()` displays details of all doctors.
- **Modify Doctor:** `modifyd()` allows modifying the details of a doctor using their ID number.
- **Delete Doctor:** `delete_docter()` removes a doctor from the system based on the ID number.

## Course Registration (Patient to Doctor)

- **Register Patient with Doctor:** The `Patient::registerCourse()` function allows a patient to register for a doctor based on the doctor's specialization and the patient's type. A `multimap` (savedpatient) is used to store the patients who are successfully registered with a particular doctor.

## Report Menu

The `report_men()` function provides a report menu for generating different kinds of reports, including patient and doctor reports.

## Missing Parts

- The code for the report generation and the menu system for different options is not fully implemented.

## Suggestions for Improvement

- **Error Handling:** Add error handling for invalid inputs (e.g., invalid phone number, age, or ID number).
- **Refactor Repeated Code:** Some functionalities like modifying and displaying data for both patients and doctors are quite similar. Consider extracting common code into reusable functions.
- **Search Functionality:** Implement a search feature to find patients or doctors by name or other criteria.
- **Data Integrity:** Consider using a database instead of CSV files for better data integrity and scalability.
