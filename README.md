#How to add Your Code

Hi there. Since we'll be working on a number of exercizes, I want to give you the opportunity to share your work with the rest of Team C/C++. That's why I'm going to give you a step-by-step tutorial on how to set up git and share your code with the rest of us.

1. [Create a GitHub account.](https://github.com/) If you don't know, GitHub is a community where programmers can contribute to projects and share their own code. If you don't have one already, you definitely will need one in the future.

2. Once you've made an account, you'll need to be able to contribute. You can download the GitHub GUI for [Windows](https://windows.github.com/) or [Mac](https://mac.github.com/). You can also use git from the terminal. In that case, you can just [download git.](http://git-scm.com/downloads) 

3. (Optional) You may follow [these instructions](https://help.github.com/articles/set-up-git#platform-all) on how to configure git on your system if you're using a terminal.

4. Go to github.com and fork [the team's repository.](https://github.com/hallfox/teamcc) When you hit fork, GitHub will automatically create a copy of the repository on your account.

5. (GUI Users) Next, go to your account at github.com/[username] and find the repository you just forked. Once you navigate to the project's page, scroll down and press the Clone in Desktop button. That will make a local version of the project on your computer. 
(Terminal Users) Next, open up your terminal and find a folder you want to keep your projects in. Type in the command `git clone https://github.com/[username]/teamcc`. This will make a local version of the project on your computer.

6. The next step depends on where your project is being kept. If you're a GUI user, there should be a settings button that looks like a gear. If you click on it, one of the options should be "Open in Explorer." Click on that and your respective file explorer program should pop up. If you're a terminal user, then just open your file explorer at the location you chose to clone your project. You should be viewing the directory of the project. Open it up.

7. Inside the folder should be a few items: a README.md file, which (this file), and a several folders named after some of the books posted on the chat. Open a few of them and read the README.md files in there to see what book each folder is about.

8. In one of those folders you should see another set of folders, or at the very least one folder named "hallfox" (me!). Create your own folder. It can be named whatever you like, preferably it's your username. We want to be able to tell who it is!

9. This folder should keep all your work on the book. This should be where you keep all your work from now on. At the very least, open the clang (The C Programming Language by K&R) folder and make a folder named after you. Inside that folder make a file named "helloworld.c". Write the "hello, world" program in C. Now you can commit a change. 

10. (GUI Users) Open your GUI and find your project. Changes have been made, so now look for the area that talks about committing changes. Add a commit message, it could be anything. Preferably it's a short yet sufficient statement on what you changed. Hit commit to save your changes.
(Terminal Users) Making a commit requires just two commands. They are:
`git add -A :/ #adds all files to the stage` and
`git commit -m "[commit message]" #commits all files on the stage` That's it!

11. Now that you've committed on your computer, you need to make changes to the repository on your GitHub account. You can do this by pressing the SYNC button if you're on GUI or by entering the command git push origin master in the terminal.

12. The final step is to make a pull request. Go back to GitHub. Check to make sure the repository on your account matches the repository on your computer. Now go back to [my version of the project.](https://github.com/hallfox/teamcc) GitHub should automatically detect that you have a different version of my original upstream project. A button should appear that says "Create Pull Request." If it doesn't, there is a tab to the right that's labelled "Pull Requests." On that page you'll find the "Create Pull Request" button.

That's it! Once you've submitted a pull request, it's in my hands to update. It should be accepted as soon as possible.
