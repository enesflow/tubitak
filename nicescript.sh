cd /home/ecr/Desktop/tubitak
echo $(pwd)
./remove.sh
git add .
git commit -am "Update"
git push origin master
echo "Done" > ./done.txt