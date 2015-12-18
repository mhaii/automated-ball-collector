##Arduino code 
####for an automated Arduino-controlled robot 
- tracking black line over blue background
- locate table tennis balls using opencv
- using video feed from smartphone's camera streaming over wifi as video source
- use serial monitor over bluetooth to communicate between the computer and the arduino

Every modules are defined in their own classes and in separated files

### CLI for git
#### Clone (download the whole repo)
- ```git clone git@github.com:mhaii/automated-ball-collector.git``` (besure to add ssh key to github first!)
- ```git clone https://github.com/mhaii/automated-ball-collector.git```

#### Add (new file or file with new changes)
- ```git add [file]```

#### Push (upload to github)
- ```git push```

#### Un-add (in case you added wrong file, or sth)
- ```git reset --soft HEAD~1``` (rollback 1 step)
- ```git reset``` (rollback to last commit)

#### Commit (save changes)
- ```git commit -m "[commit message]"``` (changes in staging)
- ```git commit -a -m "[commit message]"``` (all changes)


#### Pull (download changes from github)
- ```git pull```