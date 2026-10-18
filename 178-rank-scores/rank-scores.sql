select score, ranked.rnk as 'rank' 
from (select score ,dense_rank() over (order by score desc)as 'rnk' from Scores)as ranked 
