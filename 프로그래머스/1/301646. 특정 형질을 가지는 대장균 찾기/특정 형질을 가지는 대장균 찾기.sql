-- 코드를 작성해주세요
select count(*) as COUNT
from ECOLI_DATA
where not(GENOTYPE & 2) and (GENOTYPE & 5);