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
