**INSTALLATION for Ubuntu (program version 64-bit, Ubuntu 16.04 lts)**
----
----

#Browser
**Chrome:**

    wget -q -O - https://dl-ssl.google.com/linux/linux_signing_key.pub | sudo apt-key add - 
    sudo sh -c 'echo "deb [arch=amd64] http://dl.google.com/linux/chrome/deb/ stable main" >> /etc/apt/sources.list.d/google-chrome.list'
    sudo apt update 
    sudo apt install google-chrome-stable -y

#GIT

    sudo apt install git -y

#Java
**Instal OpenJDK8**

    sudo apt install openjdk-8-jre openjdk-8-jdk -y

**UNINSTALL OpenJDK8:**

    sudo apt autoremove openjdk-8-jre
    sudo apt purge openjdk*

**Install Oracle JDK8:**
 
 *Manually:*
  
  1. download from oracle website (http://www.oracle.com/technetwork/java/javase/downloads/index.html)
  
  2. unzip ` tar -zxvf jdk-8u111-linux-x64.tar.gz`
  
  3. create java folder ` sudo mkdir /usr/lib/java`
  
  4. move downloaded java to created folder ` sudo mv jdk.1.8.0_111 /usr/lib/java`
  
  5. update-alternatives
  
    ` sudo update-alternatives --install "/usr/bin/java" "java" "/usr/lib/java/jdk1.8.0_111/bin/java" 1`
    
    ` sudo update-alternatives --install "/usr/bin/javac" "javac" "/usr/lib/java/jdk1.8.0_111/bin/javac" 1`
    
    ` sudo update-alternatives --install "/usr/bin/javaws" "javaws" "/usr/lib/java/jdk1.8.0_111/bin/javaws" 1`
  
  6. open bashrc  `sudo gedit ~/.bashrc`
  7.  add lines

    `export JAVA_HOME=/usr/lib/java/jdk1.8.0_111`
    
    `export PATH="$PATH:$JAVA_HOME/bin"`

  8. save and exit
  
  9. check installation `java -version`


*From PPA:*  

    sudo add-apt-repository ppa:webupd8team/java
    sudo apt update
    sudo apt install oracle-java8-installer -y


#IDEs
**NetBeans**

    sudo add-apt-repository ppa:vajdics/netbeans-installer
    sudo apt update
    sudo apt install netbeans-installer -y

**CodeBlocks:**

    sudo add-apt-repository ppa:damien-moore/codeblocks-stable
    sudo apt update
    sudo apt install codeblocks  -y


#Node.JS
**Nnode.JS**

    sudo curl -sL https://deb.nodesource.com/setup_4.x | sudo -E bash -
    sudo apt install -y nodejs

 **Updating npm** 

    sudo npm install -g npm

 **Installin node-gyp**
    
    sudo npm install -g node-gyp
    sudo npm install -g node-pre-gyp


#Editors
**Notepadqq** (analog Notepad++ for windows)

    sudo add-apt-repository ppa:notepadqq-team/notepadqq
    sudo apt update
    sudo apt install notepadqq -y

**Sublime text**

    sudo add-apt-repository ppa:webupd8team/sublime-text-3
    sudo apt update
    sudo apt install sublime-text-installer -y

#Usefool tools
**umake**

    sudo add-apt-repository ppa:ubuntu-desktop/ubuntu-make
    sudo apt update
    sudo apt install ubuntu-make -y

**Grub customizer**

    sudo add-apt-repository ppa:danielrichter2007/grub-customizer 
    sudo apt update 
    sudo apt install grub-customizer -y

**Vokoscreen** (Screencast recorder)

    sudo apt install vokoscreen -y

