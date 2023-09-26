remot="Get_next_line"
url = "vogsphere.42abudhabi.ae:vogsphere/intra-uuid-18285a8d-9e16-4198-a464-bee3bc4ca0a2-5201907-mhashir"
git remote add "$remot" vogsphere.42abudhabi.ae:vogsphere/intra-uuid-18285a8d-9e16-4198-a464-bee3bc4ca0a2-5201907-mhashir
git fetch "$remot"
git merge "$remot/master" --allow-unrelated-histories -m "commited $remot"
#mv ex* "./Piscine/$remot"
git add .
git commit -m "committed $remot"
git push origin master

# for i in {5..8}; do 
#     mkdir "C0$i"       
# done