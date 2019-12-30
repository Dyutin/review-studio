# Review Studio - Movie Database Management System

Review Studio is a user-friendly and menu-driven software developed in C++. This Object-Oriented Program (OOP) allows users to efficiently manage a movie database. With Review Studio, users can create accounts, add, modify, search, and rate movies, providing a platform for sharing and evaluating movie recommendations. The software is designed to be simple and easy to use, making movie management hassle-free.

## Table of Contents

- [Introduction](#introduction)
- [Design and Implementation](#design-and-implementation)
- [Features](#features)
- [Usage](#usage)

## Introduction

Review Studio is designed to streamline the process of managing a movie database. It empowers users to create, modify, and rate movies, helping others make informed decisions about the movies they watch. This program simplifies tasks such as adding, modifying, deleting, searching, and displaying movie records.

## Design and Implementation

Review Studio is developed using the popular programming language Turbo C++. The source code is user-friendly, incorporating clear and concise messages to enhance user understanding. The program takes advantage of Object-Oriented Programming (OOP) concepts in C++, including Data Abstraction, Data Encapsulation, Modularity, and Data Hiding.

### Key Functions

The project includes various functions to achieve its functionalities:

- `menu()`: Establishes an interactive menu for easy software interaction.
- `Addadmin()`, `Adduser()`: Writes details of Admin and User accounts to respective data files.
- `NewAdmin()`, `NewUser()`: Gathers details of new Admin and User accounts.
- `disp()`, `ShowUser()`, `ShowAdmin()`: Display account and movie details.
- `details()`: Reads account login details.
- `Get_adminId()`, `Get_adminPass()`, `Get_userId()`, `Get_userPass()`: Returns login information.
- `Getmv()`, `MvDisp()`, `ViewAll()`, `GetStatus()`, `RatePort()`, `MvPort()`: Manage movie details and ratings.
- `RetUrate()`, `RetMov()`: Return user-specific movie information.
- `find()`: Identifies and directs login type.
- `AdminPage()`, `UserPage()`: Allow admin and user actions within the database.

## Features

- User-friendly menu-driven interface for easy interaction.
- Ability to create and manage Admin and User accounts.
- Efficient addition, modification, deletion, searching, and display of movie records.
- Movie rating functionality to aid in evaluating movie quality.
- Implementation of OOP concepts for code organization and readability.

## Usage

1. Clone the repository.
2. Compile and run the program using Turbo C++.
3. Follow the on-screen menu options to manage accounts and movies.
4. Use the intuitive interface to add, modify, search, rate, and display movie records.