cd /home/ecr/Desktop/tubitak
./remove.sh
git add /home/ecr/Desktop/tubitak
git commit /home/ecr/Desktop/tubitak -m "Update"
git push /home/ecr/Desktop/tubitak -u origin master
echo "Done" > /home/ecr/Desktop/tubitak/done.txt