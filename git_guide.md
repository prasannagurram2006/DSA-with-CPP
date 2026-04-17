# 🚀 Git Workflow Cheat Sheet (DSA Repo)

## 📁 Step 1: Go to Project Folder

```bash
cd C:\Users\gurra\OneDrive\Desktop\cpp\DSA
```

👉 Always start inside your repo

---

## 🔍 Step 2: Check Status

```bash
git status
```

👉 Shows:

* new files
* modified files
* deleted files

---

## ➕ Step 3: Add Files

### Add everything:

```bash
git add .
```

### OR specific:

```bash
git add slidingwin/
git add hashing/file.cpp
```

---

## 💬 Step 4: Commit Changes

```bash
git commit -m "Added sliding window problems"
```

👉 Saves changes locally

---

## 🔄 Step 5: Pull Latest Changes (IMPORTANT)

```bash
git pull origin main --rebase
```

👉 Avoids push errors

---

## 🚀 Step 6: Push to GitHub

```bash
git push
```

---

## ⚠️ First Time Only

```bash
git push --set-upstream origin main
```

---

# 🧹 Cleanup Commands

## ❌ Remove unwanted files (like .exe)

```bash
git rm --cached hashing/*.exe
```

## 🚫 Ignore files permanently (.gitignore)

Create `.gitignore` and add:

```
.vscode/
*.exe
```

---

# 🔍 Useful Commands

## 📂 List files

```bash
dir
```

## 📜 Commit history

```bash
git log --oneline
```

## ✅ Check if everything is pushed

```bash
git status
```

✔ Should show: working tree clean

---

# 🔁 Daily Workflow (REMEMBER THIS)

```bash
git status
git add .
git commit -m "Your message"
git pull origin main --rebase
git push
```

---

# ❗ Common Errors

## ❌ Push rejected

```bash
git pull origin main --rebase
git push
```

## ❌ Accidentally added .exe

```bash
git rm --cached *.exe
git commit -m "Removed exe"
git push
```

---

# 🧠 Quick Meaning

| Command    | Meaning       |
| ---------- | ------------- |
| git add    | prepare files |
| git commit | save locally  |
| git pull   | get latest    |
| git push   | upload        |

---

# 🎯 Final Goal

* Clean repo ✅
* Only `.cpp` files ✅
* No `.exe` or `.vscode` ✅
* Professional GitHub ✅
