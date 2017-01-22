godep save ./
echo "web:goalbumapp" > Procfile
go install
heroku local
git init
heroku git:remote -a blooming-dusk-36916
git add .
git commit -am "init"
git push heroku master
heroku open
heroku logs --tail
