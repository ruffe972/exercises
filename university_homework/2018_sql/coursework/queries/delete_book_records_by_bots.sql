use ershov;

--helper
select *
from book_user_record
join site_user on book_user_record.site_user_id = site_user.id

delete book_user_record
from book_user_record
join site_user on book_user_record.site_user_id = site_user.id
where bot = 1