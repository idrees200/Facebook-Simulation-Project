# Facebook Simulation Project

## Introduction

This project aims to simulate a simplified version of Facebook using object-oriented programming concepts in C++. The simulation includes users, pages, posts, comments, activities, and memories, each represented as classes with specific functionalities.

## Project Structure

The project consists of the following key components:

- **Classes**: 
  - `Helper`: Contains various static helper functions for string operations.
  - `object`: Base class for entities like users and pages.
  - `user`: Represents a Facebook user.
  - `page`: Represents a Facebook page.
  - `post`: Represents a post made by a user or page.
  - `memory`: Represents memories shared by users based on their posts.
  - `comment`: Represents comments made on posts.
  - `activity`: Represents activities associated with posts.
  - `Date`: Represents date functionalities, used for post and memory timestamps.
  - `facebook`: Represents the main simulation environment, manages users, pages, posts, etc.

- **Data Handling**:
  - Reading and writing data from/to files using `fstream`.
  - Dynamic memory allocation and deallocation for strings and objects.

- **Functionality**:
  - Adding friends, liking pages, and posting on timelines.
  - Managing comments and activities associated with posts.
  - Viewing timelines, liked pages, and friend lists.
  - Handling memories and their shared timestamps.

## Usage

To run the simulation:

1. **Compile**: Use a C++ compiler (e.g., g++) to compile the source files.
   
   ```bash
   g++ main.cpp -o facebook_simulation
EXAMPLE OUTPUT:
Welcome to the Facebook Simulation!

1. Create a user
2. Create a page
3. Make a post
4. Comment on a post
5. Add friend
6. Like a page
7. View timeline
8. View liked pages
9. View friends list
10. Exit

Enter your choice: 1

Enter user details:
Name: John Doe
Date of birth (DD-MM-YYYY): 15-07-1990
Location: New York

User John Doe created successfully!

Enter your choice: 2

Enter page details:
Page name: Technology News
Category: News

Page Technology News created successfully!

Enter your choice: 3

Enter post details:
Content: Excited about the latest tech release!
Visibility (public/private): public

Post created successfully!

Enter your choice: 4

Enter comment details:
Post ID to comment on: 1
Comment: Can't wait to read more about it!

Comment added successfully!

Enter your choice: 5

Enter username to add as friend: Alice

Alice added as a friend to John Doe!

Enter your choice: 6

Enter page name to like: Technology News

John Doe liked the page Technology News!

Enter your choice: 7

John Doe's Timeline:
1. [Public] Excited about the latest tech release! (Posted on 16-06-2024)
   - Comments:
     - Can't wait to read more about it! (Commented on 16-06-2024 by John Doe)

Enter your choice: 8

John Doe's Liked Pages:
1. Technology News

Enter your choice: 9

John Doe's Friends:
1. Alice

Enter your choice: 10

Exiting Facebook Simulation. Goodbye!

