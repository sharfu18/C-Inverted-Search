 
# C Inverted Search

## Project Introduction

The **C Inverted Search** project is a file-based word indexing and searching application developed using the C programming language. It uses a **hash table and linked lists** to create an inverted index of words present across multiple text files.

An inverted index stores each unique word along with the names of the files in which it appears and the number of times it occurs in each file. This allows users to search for a word and quickly identify the files containing it without scanning every file again.

The application supports database creation, display, searching, saving, and restoring the indexed database.

## Features

- **Database Creation:** Reads multiple text files and creates an inverted index of their words.
- **Hash Table Implementation:** Uses 27 hash buckets to organize words based on their first character.
- **Word Frequency Tracking:** Maintains the occurrence count of each word in individual files.
- **Database Display:** Displays indexed words, the number of files containing each word, and their respective word counts.
- **Word Searching:** Searches for a specific word in the created database.
- **Database Saving:** Saves the indexed database into a backup file for future use.
- **Database Restoration:** Restores the previously saved database without recreating the index from the original files.
- **Duplicate File Validation:** Prevents the same source file from being added repeatedly.

## Data Structures Used

### 1. Hash Table

The project uses a hash table containing **27 buckets**:

- Buckets 0–25 represent the English alphabets A–Z.
- Bucket 26 is used for words beginning with other characters.

The first character of each word determines its hash bucket.

### 2. Linked Lists

Two levels of linked lists are used:

- **Main Node:** Stores a unique word, the number of files containing that word, and a pointer to its sub-node list.
- **Sub Node:** Stores the filename, the number of occurrences of the word in that file, and a pointer to the next sub-node.

This structure allows multiple words to be stored in each hash bucket and each word to be associated with multiple files.

## How It Works

### 1. Database Creation

- Accepts multiple `.txt` files as input.
- Reads each file word by word.
- Determines the appropriate hash bucket using the first character of the word.
- Checks whether the word already exists in the bucket.
- If the word exists, updates its file information and occurrence count.
- If the word does not exist, creates a new main node and corresponding sub-node.

### 2. Database Display

Displays the complete inverted index, including:

- Hash table index
- Word
- Number of files containing the word
- Filename
- Number of occurrences in each file

### 3. Word Searching

- Accepts a word from the user.
- Calculates its hash bucket.
- Searches for the word in the corresponding linked list.
- If found, displays the filenames and occurrence counts.
- Otherwise, displays a message indicating that the word was not found.

### 4. Database Saving

- Saves the current inverted index into a backup file.
- Stores the hash index, word, file count, filenames, and word frequencies.
- Allows the database to be restored later without scanning the original text files again.

### 5. Database Restoration

- Reads the previously saved backup file.
- Validates the backup file format.
- Extracts the stored words, filenames, and occurrence counts.
- Reconstructs the hash table and linked-list structure in memory.

## Project Structure

```text
C-Inverted-Search/
│
├── main.c
├── create_database.c
├── display_database.c
├── search_database.c
├── update_database.c
├── save_database.c
├── validate.c
├── inverted_search.h
│
├── f1.txt
├── f2.txt
├── f3.txt
├── backup.txt
│
└── README.md
```

## File Description

| File | Description |
|---|---|
| `main.c` | Contains the main function and menu-driven application logic. |
| `create_database.c` | Creates the inverted index from input text files. |
| `display_database.c` | Displays the complete indexed database. |
| `search_database.c` | Searches for a word in the hash table. |
| `update_database.c` | Restores the database from a backup file. |
| `save_database.c` | Saves the database into a backup file. |
| `validate.c` | Performs input file and database validation. |
| `inverted_search.h` | Contains structure definitions, macros, and function declarations. |
| `f1.txt`, `f2.txt`, `f3.txt` | Sample input text files. |
| `backup.txt` | Sample saved database file. |

## Compilation

Compile all the C source files using GCC:

```bash
gcc *.c -o inverted_search
```

## Execution

Run the executable:

```bash
./inverted_search
```

## Menu Options

The application provides the following menu-driven operations:

```text
1. Create DataBase
2. Display DataBase
3. Update DataBase
4. Search a Word
5. Save DataBase
6. Exit
```

## Sample Usage

1. Run the application.
2. Select **Create DataBase** and provide the input text filenames.
3. Add the remaining text files to the database.
4. Select **Display DataBase** to view the inverted index.
5. Select **Search a Word** and enter the word to be searched.
6. Select **Save DataBase** and provide a backup filename.
7. On a future execution, select **Update DataBase** to restore the saved index.

## Concepts Learned

- Hash Tables and Hashing Techniques
- Singly Linked Lists
- Dynamic Memory Allocation
- Structures and Pointers in C
- File Handling
- String Manipulation
- Searching and Data Indexing
- Database Serialization and Restoration
- Modular Programming
- Input Validation

## Limitations

- Word searching is case-sensitive (`Hello` and `hello` are treated as different words).
- Words are separated using whitespace; punctuation is not automatically removed.
- The application is designed for text files with the `.txt` extension.
- The implementation uses fixed-size character arrays for words and filenames.

## Future Improvements

- Implement case-insensitive searching.
- Remove punctuation and normalize words before indexing.
- Improve backup file validation and error handling.
- Support larger filenames and dynamically allocated strings.
- Optimize database searching and restoration for large datasets.

## Author

**Shaik Sharfuddin**

B.Tech – Electronics and Communication Engineering

GitHub: [Add your GitHub Profile Link](https://github.com/)