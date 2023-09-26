remot="C06"

git remote add "$remot" git@vogsphere.42abudhabi.ae:vogsphere/intra-uuid-6d3f6e6a-1861-48c9-932a-b4281de7bffd-4756967-mhashir
git fetch "$remot"
git merge "$remot/master" --allow-unrelated-histories -m "commited $remot"
mv ex* "./Piscine/$remot"
git add .
git commit -m "committed $remot"
git push origin master

# for i in {5..8}; do 
#     mkdir "C0$i"       
# done