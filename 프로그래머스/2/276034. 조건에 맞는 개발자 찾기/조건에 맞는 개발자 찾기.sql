-- 코드를 작성해주세요
select ID, EMAIL, FIRST_NAME, LAST_NAME
from DEVELOPERS as D
where exists (
    select 1
    from SKILLCODES as S
    where (D.SKILL_CODE & S.CODE = S.CODE) and (S.NAME in ('C#', 'Python'))
)
order by ID;