**INSTALLATION for Ubuntu (program version 64-bit, Ubuntu 16.04 lts)**
----
----

#Browser
**Chrome:**

    wget -q -O - https://dl-ssl.google.com/linux/linux_signing_key.pub | sudo apt-key add - 
    sudo sh -c 'echo "deb [arch=amd64] http://dl.google.com/linux/chrome/deb/ stable main" >> /etc/apt/sources.list.d/google-chrome.list'
    sudo apt-get update 
    sudo apt-get install google-chrome-stable

#Java
**UNINSTALL OpenJDK8:**

    sudo apt-get autoremove openjdk-8-jre
    sudo apt-get purge openjdk*

**Install Oracle JDK8:**
 *Manually:*
  1) download from oracle website (http://www.oracle.com/technetwork/java/javase/downloads/index.html)
  2) unzip `tar -zxvf jdk-8u111-linux-x64.tar.gz`
  3) create java folder `sudo mkdir /usr/lib/java`
  4) move downloaded java to created folder `sudo mv jdk.1.8.0_111 /usr/lib/java`
  5) update-alternatives

    sudo update-alternatives --install "/usr/bin/java" "java" "/usr/lib/java/jdk1.8.0_111/bin/java" 1
    sudo update-alternatives --install "/usr/bin/javac" "javac" "/usr/lib/java/jdk1.8.0_111/bin/javac" 1
    sudo update-alternatives --install "/usr/bin/javaws" "javaws" "/usr/lib/java/jdk1.8.0_111/bin/javaws" 1

  6) add JAVA_HOME to bashrc

    sudo gedit ~/.bashrc

  add lines
	

    export JAVA_HOME=/usr/lib/java/jdk1.8.0_111
	export PATH="$PATH:$JAVA_HOME/bin"
  save and exit
  7) check installation `java -version`

 
 *From PPA:*
  

    sudo add-apt-repository ppa:webupd8team/java
    sudo apt-get update
    sudo apt-get install oracle-java8-installer

#IDEs
**CodeBlocks:**

    sudo add-apt-repository ppa:damien-moore/codeblocks-stable
    sudo apt-get update
    sudo apt-get install codeblocks

#Node.JS
**Nnode.JS**

    sudo curl -sL https://deb.nodesource.com/setup_4.x | sudo -E bash -
    sudo apt-get install -y nodejs

 **Updating npm** 

    sudo npm install -g npm

 **Installin node-gyp**

    sudo npm install -g node-gyp
    sudo npm install -g node-pre-gyp

#Editors
**Notepadqq** (analog Notepad++ for windows)

    sudo add-apt-repository ppa:notepadqq-team/notepadqq
    sudo apt-get update
    sudo apt-get install notepadqq



