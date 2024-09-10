-- 코드를 입력하세요
select apnt_no, p.pt_name, p.pt_no, a.mcdp_cd, d.dr_name, a.apnt_ymd
from appointment a
join doctor d on d.dr_id = a.mddr_id
join patient p on p.pt_no = a.pt_no
where apnt_cncl_yn = 'N' and apnt_ymd like "2022-04-13%"
order by a.apnt_ymd
