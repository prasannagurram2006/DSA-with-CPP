Basic work flow to push
git add .
git commit -m "message"
git push

That is only the starting level.

What You Should Learn Next (Placement + Real Projects)
1. Branching ⭐ MOST IMPORTANT

Right now you probably work only on main.

In real projects:

main = stable code
new features are developed in separate branches
Workflow
Create branch
git checkout -b feature-login
Work normally
git add .
git commit -m "Added login page"
Push branch
git push origin feature-login
Why branches matter

Suppose:

You are building a website
Login feature breaks code

If you work directly on main, entire project breaks.

Branches keep main safe.

2. Pull Requests (PR) ⭐ VERY IMPORTANT

After pushing a branch:

GitHub allows:

comparing changes
reviewing code
discussing improvements
merging safely

This is called a Pull Request.

Real Industry Flow
main branch
    ↓
create feature branch
    ↓
write code
    ↓
push branch
    ↓
create Pull Request
    ↓
review
    ↓
merge into main

This is used almost everywhere.

3. Clone Repository

Instead of downloading ZIP files:

git clone repo-url

Example:

git clone https://github.com/user/project.git

This copies:

files
history
branches
4. Pull Latest Changes

Suppose teammate updated repo.

You need latest code:

git pull origin main

Without pull:

conflicts happen
outdated code remains
5. Merge

Combine one branch into another.

Example:

git checkout main
git merge feature-login

Usually GitHub PR handles this automatically.

6. Merge Conflicts ⭐ IMPORTANT

Suppose:

you edited line 10
teammate also edited line 10

Git gets confused.

This becomes a merge conflict.

You manually choose:

your code
their code
both

This is a very common real-world skill.

7. .gitignore ⭐ VERY USEFUL

Some files should NOT go to GitHub:

node_modules
passwords
build files
temporary files

Example:

node_modules/
.env
dist/
8. README.md ⭐ IMPORTANT FOR PORTFOLIO

This is your project documentation.

Good README includes:

project description
features
screenshots
setup steps
tech stack

This matters a lot in internships.

9. Forking

Fork = copy someone else's repo to your GitHub account.

Used in:

open source contributions
practice

Workflow:

Fork repo
↓
Clone fork
↓
Make changes
↓
Push
↓
Create PR to original repo
10. GitHub Issues

Used for:

bug tracking
feature requests
task assignment

Example:

Issue #12: Login button not working

Teams manage projects using Issues.

11. GitHub Actions (CI/CD) 🚀

Automation feature.

Example:

automatically run tests
deploy website
check build errors

Whenever you push code.

Very useful later.

12. Stash

Temporarily save unfinished work.

git stash

Bring back:

git stash pop

Useful when switching branches quickly.

13. Revert vs Reset
Revert

Safely undo commit:

git revert commit_id
Reset

Dangerous rewrite:

git reset --hard HEAD~1