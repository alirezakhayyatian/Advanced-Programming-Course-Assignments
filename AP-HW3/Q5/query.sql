------------1------------------------------
select* from users where phone = '09120000001';
-----------2------------------------
update users set email = 'apstudent2019@gmail.com' where phone = '09120000001';
select email from users where phone = '09120000001';	

------------3-----------------------

select title from channel where id in
( select channel_id from channelmembership where user_id in
	(select id from users where phone = '09120000001') );
-----------4-------------


select count(user_id) from channelmembership where channel_id 
in(select id from channel where telegram_id ='@aut_ap_2019');
-----------5--------------------

select email from users where phone like '0935%';
-----------6------------------

select phone from users where id in(
	select blocked_user_id from blockuser where
	blocker_user_id in(select id from users where phone = '09120000001')
    and
	ecreated_at::date > date'2019-03-10');
----------7--------------------------

select email from users where id in(
select creator_id from channel where id in(	
select channel_id from channelmembership where user_id in (select id from users where email = 'apstudent2019@gmail.com') and
 channel_id in(select channel_id from channelmembership group by channel_id having count(*) > 3)  )  );
-------------8---------------------


select message_text from message where  create_at in(select create_at from message order by create_at desc limit 11) and
(
    (sender_id in(select id from users where telegram_id = '@amir.jahanshahi')
    and
    receiver_id in(select id from users where telegram_id = '@sHDiV4RHs') )
or     

    (sender_id in(select id from users where telegram_id = '@sHDiV4RHs')
    and
    receiver_id in(select id from users where telegram_id = '@amir.jahanshahi') )
);    


delete from message where

(
    (sender_id in(select id from users where telegram_id = '@amir.jahanshahi')
    and
    receiver_id in(select id from users where telegram_id = '@sHDiV4RHs') )
or     

    (sender_id in(select id from users where telegram_id = '@sHDiV4RHs')
    and
    receiver_id in(select id from users where telegram_id = '@amir.jahanshahi') )
);    


-------------------------9---------------------------------
select* from message where create_at::date =date '2019-04-11';

select message_text from channelmessage where update_at in( (
	select update_at from channelmessage order by update_at desc limit 3) < '2019-04-10 14:25:32');






select distinct channel_id from channelmessage where update_at::date < date'2019-03-11';

select distinct message_text from channelmessage where update_at::date < date'2019-03-11';





    select message_text from channelmessage (select create_at as mydate from channelmessage order by create_at desc limit 1) 
    where 
    mydate::date < date'2019-04-03'


	select message_text from channelmessage
	where mydate::date < date'2019-04-03');



select phone from users where id in
(
select user_id from channelmembership where channel_id in
(
select distinct channel_id from channelmessage where create_at in
(
select create_at 
from
(select channelmessage.create_at ,channel.id
from  channelmessage ,channel
where  channelmessage.channel_id = channel.id) as asd

where create_at::date < date'2019-04-03'
)

)

);








select create_at  
from
(select channelmessage.create_at ,channel.id
from  channelmessage ,channel
where  channelmessage.channel_id = channel.id) as asd
where create_at::date < date_trunc('month', now()) - interval '1 month'
      
group by id;



select channel_id from channelmessage where create_at not between now()-interval '1' month and now();

(select create_at from channelmessage order by create_at desc limit 1) adc



select create_at  
from
(select channelmessage.create_at ,channel.id
from  channelmessage ,channel
where  channelmessage.channel_id = channel.id) as asd
order by create_at desc limit 1 



select create_at from channelmessage where channel_id in(select id from channel) 



