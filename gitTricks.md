GIT TRICKS
----
----

**add file to fresh unpushed commit**

```
# add file-that-i-remember.txt
git add file-that-i-remember.txt
git commit

# realize you forgot a file
git add file-that-i-forgot.txt
git commit --amend --no-edit
```
