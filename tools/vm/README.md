# VM manual

For everyone that is in doubt or have problem with their setup, we strongly recommend that you use the virtual image. Especially moving forward we will use tools that we cannot guarantee will work correctly on non-Linux machines and building some will require different language and a more extensive tool chain that you have previously used on the course. Though installation it not too hard, you cannot expect us to support any problems with installation on your machine.

Instead we will support and guarantee continues updates of an VM image. In the following we will guide you to how you can easiest interact with the VM that you set up. Generally, you can expect that the image will be updated. We therefore give two ways of avoiding having data or easily synchronising data to/from the VM.

In this directory there are several scripts (explained below) that can help you connect from Linux and OS X. You might need to make them executable using `chmod` by calling:

```
chmod u+x <file>
```


## Install Virtual Box
First, you need to install Virtual Box for your OS, which you find on the link below:

https://www.virtualbox.org/

### macOS permissions
On newer macbooks the installation can fail. In that case you need to the Security & Privacy setting and give the installation program full permissions.

### Virtualisation Technology
For efficiently running the VM you need to have enabled Intel Virtualisation Technology (Intel VT) or AMD-Virtualisation (AMD-V), depending on your processor provider. If you get the error 

```
VT-x is disabled in the BIOS for all CPU modes (VERR_VMX_MSR_ALL_VMX_DISABLED)
```

or similar, you need to enter your BIOS setup and update this. This is very architecture specific, so you need to search how to solve this.


## The VM image
On the following link you find the image from CompSys 2017. You can use now this to test your workflow, but it also works with for our basic needs. We will later provide an updated image with the relevant tools.

* [16.09.2019] http://topps.diku.dk/compsys/compSys19-v1.1-debian-64bit.ova
* [03.09.2019] http://topps.diku.dk/compsys/compSys19-v1.0-debian-64bit.ova


The VM has the following credentials:
* login: neumann
* password: hamster

You can install the image using the "Install Appliances" item under "File" in the menu or using the command
```
VBoxManage import <file>.ova
```

## Startup of VM
The image does not have a standard GUI and all interaction should be done though the terminal. To get the most smooth interaction we therefore recommend that you start in headless (without a window from Virtual Box) setting. You can do this from the start button, or with the following command, which have also been provided in the `startup.sh` script:
```
VBoxManage startvm <file> --type headless
```

## Connection to VM
After starting the VM, you need to interact with the OS using ssh. For this you need the previous given credentials and the following connection information:
* hostname: localhost
* port: 1339

Windows users can use PuTTY or the Linux subsystem. Other users can use their preferred terminal to connect using the `ssh`-client. The ssh connection above (except the password) can be called using the `login.sh` script.

After login all commands will be on the virtual Linux machine and will traverse the file system on this machine; not your own.

## Data access on VM
As mentioned avoid having data on the VM that you do not regularly synchronise to other places, as we might provide updated images you have to use. And in general you just want this virtual machine for execution purposes and not data storage.

I do not know how well (and even if) the following works on Windows (in Linux subsystems). To be tested...

Central to the following is `sshfs` with which you can mount a file system over ssh. You can install this with the standard package manager
* OS X: `brew install sshfs`
* Linux (e.g): `apt-get install sshfs`


There are two approaches are sketched below.

### Synchronise/local mount
The basic idea here is:
 * Mount the file system on the VM to your local file system, so you can edit using your standard editor.
 * Use git on the VM to ensure that relevant data is not only on the VM and share it with your group
 * Compile and execute your code on the VM (logged-in terminal)

To mount the file system you need to call

```
sshfs neumann@localhost:. <localdir> -ovolname=compSys -oport=1339
```

This have also been included in the script `mount.sh` that you can use by calling

```
./mount.sh <localdir>
```

To unmount the file system again call

```
umount <localdir>
```

### Reverse mount
The basic idea here is:
 * Mount part of your local file system to the VM; again you can edit using your local editor on your local files.
 * Compile and execute your code on the VM (logged-in terminal)
 * You should still use git on your machine to share with your group

This requires that you have an ssh server installed and running on your machine. On OS X you do this by going to "Preferences" -> "Sharing" and enabling "Remote login". __THIS IS VERY IMPORTANT__

First you need to setup which directory that you want to have mounted on the VM. You do this by calling

```
./setup_rev_mount.sh <localdir>
```

We recommend that your restrict this at much as possible. Use only your CompSys-related directory. Mounting your entire file system can be a security risk.

Next, you need to make the VM know your current IP address. You do by calling the script

```
./rev_mount.sh
```

which transfers all information to the VM and therefore requires the login information to the VM. You need to run this script every time you change IP address; i.e. when you move between networks (home to Eduroam) and even when having your machine closed for some time.

Now you need to transfer `mount.sh` to the VM. You can do this my mounting the VM file system and described above. Everything is ready and you can login to the VM. Here you mount your local directory by calling the script `mount.sh` with the directory you want to mount to

```
./mount.sh <localdir>
```

Write `yes` when you are asked about the authenticity of host.

To unmount the file system again call

```
sudo umount <localdir>
```


## Shutdown of VM
When logged into the VM you can shut is down by calling

```
sudo shudown -h now
```
