<#assign pagetitle = "Java dans le hard(ware)">
<#include "header.ftl">
	
	<#include "menu.ftl">

	<div class="page-header">
            <div class="row">
                <div class="col-xs-4 col-md-2"><img src="/blog/img/cafe-leopard-h150.png"></div>
                <div class="col-xs-12 col-md-8"><h1>Java dans le hard(ware)</h1></div>
            </div>
	</div>
	<#list posts as post>
  		<#if (post.status == "published")>
  			<a href="/blog${post.uri}"><h1>${post.title}</h1></a>
  			<p>${post.date?string("dd MMMM yyyy")}</p>

                        <a href="https://twitter.com/share" class="twitter-share-button" data-url="http://lhuet.github.io/blog${post.uri}" data-text="${post.title}" data-via="lhuet35" data-lang="fr">Tweeter</a>
                        <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?'http':'https';if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+'://platform.twitter.com/widgets.js';fjs.parentNode.insertBefore(js,fjs);}}(document, 'script', 'twitter-wjs');</script>
                        <div class="g-plusone" data-size="medium" data-href="http://lhuet.github.io/blog${post.uri}"></div>

  			<p>${post.body}</p>
                        <p><a href="/blog${post.uri}#disqus_thread">Commentaires</a></p>
  		</#if>
  	</#list>
	
	<hr />
	
	<p>Billets plus anciens disponibles sur la page <a href="/blog/${config.archive_file}">archive</a>.</p>

<#include "footer.ftl">