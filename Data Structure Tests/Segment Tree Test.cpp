<!DOCTYPE html>
<html lang="en">
<head>
<title>Login - DMOJ: Modern Online Judge</title>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta name="keywords" content="DMOJ,Canadian,Don Mills,DMCI,online judge,programming,code,contest,CCC,CCC Solutions,CCC 2015,IOI,JOI,COCI,DMOPC,Canada,Ontario,Toronto,grade,interactive">
<meta id="viewport" name="viewport" content="width=device-width, initial-scale=1">

<link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-57x57.png">
<link rel="apple-touch-icon" sizes="60x60" href="/apple-touch-icon-60x60.png">
<link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-72x72.png">
<link rel="apple-touch-icon" sizes="76x76" href="/apple-touch-icon-76x76.png">
<link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114x114.png">
<link rel="apple-touch-icon" sizes="120x120" href="/apple-touch-icon-120x120.png">
<link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144x144.png">
<link rel="apple-touch-icon" sizes="152x152" href="/apple-touch-icon-152x152.png">
<link rel="apple-touch-icon" sizes="180x180" href="/apple-touch-icon-180x180.png">
<link rel="icon" type="image/png" href="/favicon-32x32.png" sizes="32x32">
<link rel="icon" type="image/png" href="/android-chrome-192x192.png" sizes="192x192">
<link rel="icon" type="image/png" href="/favicon-96x96.png" sizes="96x96">
<link rel="icon" type="image/png" href="/favicon-16x16.png" sizes="16x16">
<link rel="manifest" href="/manifest.json">
<meta name="msapplication-TileColor" content="#FFBB33">
<meta name="msapplication-TileImage" content="/mstile-144x144.png">
<meta name="theme-color" content="#FFBB33">
<meta property="og:site_name" content="DMOJ: Modern Online Judge">
<meta property="og:url" content="https://dmoj.ca/accounts/login/?next=/src/600633/raw">
<!--[if lt IE 9]>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/html5shiv/3.7.3/html5shiv.min.js"></script>
    <script>window.bad_browser = true</script>
    <![endif]-->
<link rel="stylesheet" href="//dmoj.algome.me/static/cache/css/5405fbc8cd00.css" type="text/css" /> <link rel="canonical" href="https://dmoj.ca/accounts/login/?next=/src/600633/raw">
<style>
        #login-panel {
            position: relative;
            margin: 5em auto auto -10em;
            top: 40%;
            left: 50%;
        }

        h4 {
            padding-top: 1em;
        }

        .social {
            display: inline;
            font-size: 2.3em;
            float: none;
        }

        .google-icon i {
            color: #DD4B38;
        }

        .facebook-icon i {
            color: #133783;
        }

        .github-icon i {
            color: black;
        }

        .dropbox-icon i {
            color: #55ACEE;
        }
    </style>
<script type="text/javascript" src="//dmoj.algome.me/static/cache/js/4f753e457100.js"></script>
<script>window.user = {};</script>
<script>window.user && Raven.setUserContext(window.user)</script>
<script>
  (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
  (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
  m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
  })(window,document,'script','https://www.google-analytics.com/analytics.js','ga');

  ga('create', 'UA-56757436-1', 'auto');
  ga('require', 'displayfeatures');
  ga('send', 'pageview');

</script>
<noscript>
        <style>
            #content {
                margin: 80px auto auto;
            }

            #navigation {
                top: 27px;
            }
        </style>
    </noscript>
</head>
<body>
<nav id="navigation" class="unselectable">
<div id="nav-container">
<a id="navicon" href="javascript:void(0)"><i class="fa fa-bars"></i></a>
<ul id="nav-list">
<li class="home-nav-element"><a href="/"><img src="//dmoj.algome.me/static/icons/logo.d0dbdf0b98be.svg" alt="DMOJ" width="160" height="44" onerror="this.src=&quot;//dmoj.algome.me/static/icons/logo.2f426bc39826.png&quot;; this.onerror=null" style="border: none"></a></li>
<li class="home-nav-element"><span class="nav-divider"></span></li>
<li class="home-menu-item"><a href="/" class="nav-home">Home</a></li>
<li>
<a href="/problems/" class="nav-problem">
Problems
</a>
</li>
<li>
<a href="/submissions/" class="nav-submit">
Submissions
</a>
</li>
<li>
<a href="/users/" class="nav-user">
Users
</a>
</li>
<li>
<a href="/contests/" class="nav-contest">
Contests
</a>
</li>
<li>
<a href="/about/" class="nav-about">
About
</a>
<ul> <li>
<a href="/status/" class="nav-status">
Status
</a>
</li>
<li>
<a href="/tips/" class="nav-tips">
Tips
</a>
</li>
<li>
<a href="/api/" class="nav-api">
API
</a>
</li>
<li>
<a href="https://github.com/DMOJ" class="nav-github">
Github
</a>
</li>
</ul> </li>
</ul>
<span id="user-links">
<span class="anon">
<a href="/accounts/login/?next=">
<b>Login</b>
</a>&nbsp;|&nbsp;<a href="/accounts/register/">Register</a>
</span>
</span>
</div>
<div id="nav-shadow"></div>
</nav>
<div id="page-container">
<noscript>
        <div id="noscript">This site works best with JavaScript enabled.</div>
    </noscript>
<br>
<main id="content">
<h2 style="color:#393630; display:inline">
Login </h2>
<hr>
<div id="content-body"> <div id="login-panel">
<form action="" method="post" class="form-area">
<input type='hidden' name='csrfmiddlewaretoken' value='hhU8pP4bOHYmCuEABKHfe84FMappTpqDmuhLvMdurQ53Ag7vVPalF6yNSeCcoE5L' /> <table border="0" style="text-align:left">
<tr>
<th><i class="fa fa-user fa-fw"></i>
</th>
<td><input type="text" name="username" autofocus required placeholder="Username" id="id_username" maxlength="254" />
</td>
</tr>
<tr>
<th><i class="fa fa-key fa-fw"></i>
</th>
<td><input type="password" name="password" required placeholder="Password" id="id_password" />
</td>
</tr>
</table>
<hr>
<button style="float:right;" type="submit">Login!</button>
<input type="hidden" name="next" value="/src/600633/raw">
</form>
<br><a href="/accounts/password/reset/">Forgot your password?</a>
<h4>Or log in with...</h4>
<a href="/login/google-oauth2/?next=/src/600633/raw" class="social google-icon">
<i class="fa fa-google-plus-square"></i>
</a>
<a href="/login/facebook/?next=/src/600633/raw" class="social facebook-icon">
<i class="fa fa-facebook-square"></i>
</a>
<a href="/login/github-secure/?next=/src/600633/raw" class="social github-icon">
<i class="fa fa-github-square"></i>
 </a>
<a href="/login/dropbox-oauth2/?next=/src/600633/raw" class="social dropbox-icon">
<i class="fa fa-dropbox"></i>
</a>
</div>
</div>
</main>
<footer>
<span id="footer-content">
<br>
<a style="color: rgb(128, 128, 128)" href="//github.com/DMOJ/">fork us on <span style="font-weight:bold">Github</span></a> | <a style="color: rgb(128, 128, 128);" href="//www.facebook.com/dmoj.ca">like us on <span style="font-weight: bold;">Facebook</span></a> | <a style="color: rgb(128, 128, 128)" href="https://translate.dmoj.ca/">help us <span style="font-weight: bold;">translate</span></a> | <a style="color: rgb(128, 128, 128)" href="https://dmoj.ca/tos/">terms of service</a> |
<form action="/i18n/setlang/" method="post" style="display: inline">
<input type='hidden' name='csrfmiddlewaretoken' value='hhU8pP4bOHYmCuEABKHfe84FMappTpqDmuhLvMdurQ53Ag7vVPalF6yNSeCcoE5L' /> <input name="next" type="hidden" value="/accounts/login/?next=/src/600633/raw">
<select name="language" onchange="form.submit()" style="height: 1.5em">
<option value="de">
Deutsch (de)
</option>
<option value="en" selected>
English (en)
</option>
<option value="es">
espa�ol (es)
</option>
<option value="fr">
fran�ais (fr)
</option>
<option value="hr">
Hrvatski (hr)
</option>
<option value="ko">
??? (ko)
</option>
<option value="ro">
Rom�n? (ro)
</option>
<option value="ru">
??????? (ru)
</option>
<option value="sr-latn">
srpski (latinica) (sr-latn)
</option>
<option value="vi">
Ti�?ng Vi�?t (vi)
</option>
<option value="zh-hans">
???? (zh-hans)
</option>
</select>
</form>
</span>
</footer>
</div>
</body>
</html>