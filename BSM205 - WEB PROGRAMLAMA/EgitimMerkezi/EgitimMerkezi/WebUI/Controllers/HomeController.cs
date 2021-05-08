using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using WebUI.Models;
using WebUI.Models.Data;

namespace WebUI.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            using (EgitimMerkeziContext context = new EgitimMerkeziContext())
            {
                AnaSayfaDTO anaSayfa = new AnaSayfaDTO();
                anaSayfa.slider = context.Slider.Where(x => (x.BaslangicTarih <= DateTime.Now && x.BitisTarih > DateTime.Now)).ToList();
                anaSayfa.duyuru = context.Duyuru.OrderByDescending(x=> x.DuyuruTarih).Take(3).ToList();
                anaSayfa.referans = context.Referans.OrderByDescending(x => x.ReferansTarih).Take(3).ToList();
                anaSayfa.blog = context.Blog.OrderByDescending(x => x.BlogTarih).Take(3).ToList();
                return View(anaSayfa);
            }
        }
        public ActionResult About()
        {
            using (EgitimMerkeziContext context = new EgitimMerkeziContext())
            {
                List<Takim> hakkimizda = context.Takim.OrderBy(x=> x.AdSoyad).ToList();
                return View(hakkimizda);
            }
        }
        public ActionResult Contact()
        {
            ViewBag.Message = "İletişim";

            return View();
        }
        public ActionResult Modules()
        {
            using (EgitimMerkeziContext context = new EgitimMerkeziContext())
            {
                List<Modul> moduller = context.Modul.OrderBy(x => x.ModulBaslik).ToList();
                return View(moduller);
            }
        }
        public ActionResult ModuleDetails(int ModulID)
        {
            using (EgitimMerkeziContext context = new EgitimMerkeziContext())
            {
                Modul modulDetay = context.Modul.FirstOrDefault(x => x.ID == ModulID);
                return View(modulDetay);
            }
        }
        public ActionResult Blog()
        {
            using (EgitimMerkeziContext context = new EgitimMerkeziContext())
            {
                List<Blog> blog = context.Blog.OrderByDescending(x => x.BlogTarih).ToList();
                return View(blog);
            }
        }
        [HttpPost]
        public ActionResult Contact(Oneri iletisimform)
        {
            try
            {
                using (EgitimMerkeziContext context = new EgitimMerkeziContext())
                {
                    Oneri _iletisimform = new Oneri();
                    _iletisimform.AdSoyad = iletisimform.AdSoyad;
                    _iletisimform.Telefon = iletisimform.Telefon;
                    _iletisimform.Eposta = iletisimform.Eposta;
                    _iletisimform.Mesaj = iletisimform.Mesaj;
                    _iletisimform.Tarih = DateTime.Now;
                    context.Oneri.Add(_iletisimform);
                    context.SaveChanges();
                    TempData["Mesaj"] = "Form Başarıyla gönderilmiştir.";
                    return View();
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Eklerken hata oluştu");
            }
        }
    }
    public class AnaSayfaDTO
    {
        public List<Slider> slider { get; set; }
        public List<Duyuru> duyuru { get; set; }
        public List<Referans> referans { get; set; }
        public List<Blog> blog { get; set; }
    }
}