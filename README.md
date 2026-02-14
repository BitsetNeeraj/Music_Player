# 🎵 Console Music Player in C

![Language](https://img.shields.io/badge/Language-C-blue)
![Library](https://img.shields.io/badge/Audio-miniaudio-green)
![Build](https://img.shields.io/badge/Build-GCC-orange)
![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey)
![Status](https://img.shields.io/badge/Status-Learning%20Project-brightgreen)

A lightweight console-based music player built in **C** using the **miniaudio** single-header audio library.  
This project demonstrates linked lists, dynamic memory allocation, and audio playback in C.

---

## 🚀 Features

- 🎶 Plays `.mp3`,`.mpeg`,`.wav` and more audio files  
- 🔁 Linked list based playlist system  
- ⏱ Displays song duration in seconds  
- 🧠 Dynamic memory allocation  
- 🖥 Sequential console playback  

---

## 🛠 Tech Stack

- **C Programming Language**
- **miniaudio (single-header audio library)**
- **GCC Compiler**

---

## 📂 Project Structure

```
Music_Player/
├── meme/
|  ├── music.mp3
|  ├── ...
|  ├── kuch.mp3
├── songs/
|  ├── dil.mp3
|  ├── ...
|  ├── indila.mp3
├── circular_linked_list.c
├── double_linked_list.c
├── miniaudio.h
├── player.c
├── simple_linked_list.c
├── README.md
```


---

## ⚙️ How It Works

1. Initializes the miniaudio engine.
2. Creates a linked list of songs.
3. Loads and plays each song sequentially.
4. Waits until playback finishes.
5. Cleans up the audio engine before exiting.

---

## ▶️ Build & Run

### 🔹 Compile

```bash

gcc filename.c -o filename.exe
```

---

### 🔹 Run

```bash

./executable_file
```

---

## 📌 Requirements

- GCC installed
- `miniaudio.h` in project directory
- Audio files in the same folder as executable

---

## 📚 Concepts Demonstrated

- Linked Lists in C  
- Structs & Pointers  
- Dynamic Memory Allocation (`malloc`)  
- File-based Audio Playback  
- Resource Management  

---

## 🔮 Future Improvements

- ⏸ Pause / Resume  
- ⏭ Next / Previous Track  
- 🔁 Loop Mode  
- 🔀 Shuffle Mode  
- 🎛 Volume Control  
- 📂 Auto-load songs from folder  

---

## 👹 Author

**Team DANV [ दानव ]**
Programming ka Raakshas, Logic ka Maharathi.

---

⭐ If you like this project, consider giving it a star!
